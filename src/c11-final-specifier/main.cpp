// more info @ https://en.cppreference.com/w/cpp/language/final

struct A {
  virtual void foo();
};

struct B : A {
  virtual void foo() final;
};

struct C : B {
  // next file is an error: declaration of 'foo' overrides a 'final' function
  // virtual void foo(); 
};

struct D final {};
// next line is an error: base 'D' is marked 'final'
// struct E : D {}; 

int main()
{
  return 0;
}
