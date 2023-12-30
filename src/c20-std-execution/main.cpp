#include <cstdio>
#include <string>
#include <thread>

#include <execution>
using namespace std::literals;

// A simple event loop:
stdexec::run_loop loop;

std::thread worker([]{ loop.run(); });

int main() {
  using namespace stdexec;

  // An "async" operation that sends a string when complete
  sender auto hello = just("hello world"s);

  // A continuation that writes the string to cout:
  sender auto print = hello
                    | then([](auto msg) {
                        std::puts(msg.c_str());
                        return 0; // <-- result of the async operation
                      });

  // A scheduler for launching work on a separate io worker thread:
  scheduler auto io_thread = loop.get_scheduler();

  // An async operation that runs on the separate io worker thread:
  sender auto work = on(io_thread, print);

  // Launch the work and wait for it to complete (this returns
  // and optional<tuple<int>>):
  auto [result] = sync_wait(work).value();

  // Tell the loop we're not going to add more work:
  loop.finish();

  // Wait for the worker thread to exit:
  worker.join();

  return result;
}
