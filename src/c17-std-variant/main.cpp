// more info @ https://www.cppstories.com/2023/finite-state-machines-variant-cpp/

#include <iostream>
#include <variant>
#include <string>

namespace helper {
    template<class... Ts> struct overload : Ts... { using Ts::operator()...; };
    // explicit deduction guide (not needed as of C++20)
    template<class... Ts> overload(Ts...) -> overload<Ts...>;
}

namespace state {
    struct PlayerAlive { unsigned int health_{ 0 }; unsigned int remainingLives_{ 0 }; };
    struct PlayerDead { unsigned int remainingLives_{ 0 }; };
    struct GameOver { };
}

using HealthState = std::variant<state::PlayerAlive, state::PlayerDead, state::GameOver>;

namespace event {
    struct HitByMonster { unsigned int forcePoints_{ 0 }; };
    struct Heal { unsigned int points_{ 0 }; };
    struct Restart { unsigned int startHealth_{ 0 }; };
}

using PossibleEvent = std::variant<event::HitByMonster, event::Heal, event::Restart>;

HealthState onEvent(const state::PlayerAlive& alive, const event::HitByMonster& monster) {
    std::cout << "PlayerAlive -> HitByMonster force " << monster.forcePoints_ << '\n';
    if (alive.health_ > monster.forcePoints_)
    {
        return state::PlayerAlive{ alive.health_ - monster.forcePoints_, alive.remainingLives_ };
    }

    if (alive.remainingLives_ > 0)
        return state::PlayerDead{ alive.remainingLives_ - 1 };

    return state::GameOver{};
}

HealthState onEvent(const state::PlayerAlive& alive, const event::Heal& healingBonus) {
    std::cout << "PlayerAlive -> Heal points " << healingBonus.points_ << '\n';

    return state::PlayerAlive{ alive.health_ + healingBonus.points_, alive.remainingLives_ };;
}

HealthState onEvent(const state::PlayerDead& dead, const event::Restart& restart) {
    std::cout << "PlayerDead -> restart" << '\n';

    return state::PlayerAlive{ restart.startHealth_, dead.remainingLives_ };
}

HealthState onEvent(const state::GameOver& over, const event::Restart& restart) {
    std::cout << "GameOver -> restart" << '\n';

    std::cout << "Game Over, please restart the whole game!\n";

    return over;
}

HealthState onEvent(const auto&, const auto&) {
    throw std::logic_error{ "Unsupported state transition" };
}

class GameStateMachine {
    public:
        void startGame(unsigned int health, unsigned int lives) {
            state_ = state::PlayerAlive{ health, lives };
        }

        void processEvent(const PossibleEvent& event) {
            state_ = std::visit(helper::overload{
                    [](const auto& state, const auto& evt) {
                    return onEvent(state, evt);
                    }
                    },
                    state_, event);
        }

        void reportCurrentState() {
            std::visit(
                    helper::overload{ [](const state::PlayerAlive& alive) {
                    std::cout << "PlayerAlive " <<  alive.health_  << " remaining lives " << alive.remainingLives_ << '\n';
                    },
                    [](const state::PlayerDead& dead) {
                    std::cout << "PlayerDead, remaining lives " << dead.remainingLives_ << '\n';
                    },
                    [](const state::GameOver& over) {
                    std::cout << "GameOver" << '\n';
                    }
                    },
                    state_);
        }

    private:
        HealthState state_;
};

void GameHealthFSMTest() {
    std::cout << "sizeof(HealthState):   " << sizeof(HealthState) << '\n';
    std::cout << "sizeof(PossibleEvent): " << sizeof(PossibleEvent) << '\n';

    GameStateMachine game;
    game.startGame(100, 1);

    try {
        game.processEvent(event::HitByMonster {30});
        game.reportCurrentState();
        game.processEvent(event::HitByMonster {30});
        game.reportCurrentState();
        game.processEvent(event::HitByMonster {30});
        game.reportCurrentState();
        game.processEvent(event::HitByMonster {30});
        game.reportCurrentState();
        game.processEvent(event::Restart {100});
        game.reportCurrentState();
        game.processEvent(event::HitByMonster {60});
        game.reportCurrentState();
        game.processEvent(event::HitByMonster {50});
        game.reportCurrentState();
        game.processEvent(event::Restart {100});
        game.reportCurrentState();

    }
    catch (std::exception& ex) {
        std::cout << "Exception! " << ex.what() << '\n';
    }
}

int main()
{
    GameHealthFSMTest();
}

