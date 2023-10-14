## directory content

**TestStepper.h**
```
The test stepper
solves a great disadvantage of CppUTest:

when CppUTest exits a test due to an unmatched expectation
it only provides
- the test name
- the source line of the test's begin
so if you have a test with some amount of lines
you will have a hard time to figure out
where exactly the mismatch happens

using TestStepper's STEP() macro
will provide you with line of the last STEP() macro placed

the STEP() macro also helps
to give your tests a more readable structure

see TestStepper documentation on github for more details
```

**TestStepperPlugin.h**
```
CppUTest plugin to invoke TestStepper
```
