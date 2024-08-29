# TDD Foundations

## "Unit" Tests

- "Unit" is smallest testable piece of system.
- A good test has (a) descriptive name and (b) clear, ordered steps.
    - Name summarizes the behaviour under test.
    - Steps demonstrate the summarized behaviour.
- Steps follow Given-When-Then (or Arrange-Act-Assert) structure.
    - Given context. Test sets this up, _if_ fixture hasn't already.
    - When stimulus. Test invokes the behaviour to be verified.
    - Then response. Test checks the system behaves as expected.
- Related tests are logically grouped into fixtures.
    - Multiple fixtures can test behaviour sets of one class.
    - One fixture can test related behaviours across classes.
- When picking a unit testing tool, ensure it:
    - Executes each test in an independent, isolated context.
    - Separates out common setup and teardown steps at fixture level.
    - Supports highly expressive assert statements.
- After-the-fact testing is complex to write and maintain, because:
    - System tends not to be designed with testability in mind.
    - Tests tend to focus then on implementation over behaviour.
- Before-the-fact test-driving keeps test granularity small and simple.
    - Because each test represents smallest meaningful increment or "unit".
    - The best tests have 2-3 lines (Given-When-Then). If longer, consider if doing too much.
    - Small increments make fast iterations: only a few minutes per "unit" of new code.
- Unit tests only cover their own units in isolation.
    - They don't concern wider (end-to-end) functionality. That's for "integration" tests.
    - Unit tests are faster i.e. more reliable when iterating in the TDD process.
- But "units" have boundaries and so interact externally eventually.
    - Can use "test doubles" to break (mock) external dependencies and continue _unit_ testing.
    - Can also (in addition) move into realm of _integration_ testing, if possible at that point.

## Red-Green-Refactor Cycle

- Short feedback loop that drives development.
    - Red: write a failing test.
    - Green: write behaviour to pass the test.
    - Refactor: improve design without changing behaviour.
- Make this process second nature to free the mind to think about the _real_ challenge: building high quality code.
    - TDD is simple, but not mindless. Much meaty problem-solving happens along the way. Some examples below.
- Write small test.
    - What next unit to increment system by?
    - The test assumes an interface. Is it the best way to use system?
    - Is the test highly expressive in how it documents behaviour?
- Ensure new test fails.
    - If not, see 'Green on Red' section below for questions to ask.
- Write code to pass test.
    - Is it the minimum code necessary?
    - Jot notes on where new code needs cleaning.
- Ensure all tests pass.
    - If new test still fails, is the new code enough? Is the test wrong?
    - If old test now fails, how did the new code break existing behaviour?
- Clean up new changes.
    - Any code smells? Duplication, hardcoding, coupling, etc.
    - Good design principles in overall design of system so far?
    - Other code (that you didn't touch) need design updates?
    - Do tests need refactoring for greater brevity, readability?
- Ensure all tests pass.
    - If not, what in the refactor broke it?
    - If yes, do the current set of tests offer enough confidence?

## Three Rules

1. Write production code only to pass a failing unit test.
    - In other words, write tests first.
    - Specify, via test, behaviour you _will_ build.
2. Write no more of a unit test than sufficient to fail (compile fails too).
    - In other words, proceed as incrementally as possible, getting feedback as soon / early as possible.
    - Controversial; case-by-case basis. Sometimes, long build times. Other times, more effective to flesh out design of a full test first.
3. Write no more production code than necessary to pass the one failing unit test.
    - In other words, write only what the current set of tests specifies / requires.
    - If violated, Rule 1 won't work (next test won't fail) and the process breaks down.

## 'Green On Red'

Important to get red first. Not just a ritual.
- After adding behaviour required by the new test, running tests won't give any real feedback, since they passed even before.
- Or worse, if you proceed thinking the green means the new behaviour is correct, this can lead to writing untested code under the illusion of test-driven safety.

Premature passes can happen if you:
- Run the wrong tests.
    - New test won't run if: didn't build, was disabled, filtered subset omits it.
    - (Action) Pay attention to test count in logs. Even better, find the new test's name.
- Test the wrong code.
    - Didn't save or build. Or build failure went unnoticed. Or built, but not linked in.
    - Testing wrong class e.g mocked class or mere interface, not the real deal.
- Expect the wrong behaviour.
    - Asserting the opposite response to what you actually want.
- Incorrectly assumed the specified behaviour is new.
    - (Action) Examine the system for this already-existing behaviour. Understand, then move on.
    - Good thing! Increases understanding of system _and_ its external dependencies.
- Incremented system in an unfortunate order.
    - Sometimes the chosen path of progression is simply 'optimal'. It covers multiple bases early on, even with the simplest, most minimal code (Rule 3).
- Conceptually linked (coupled) production code.
    - Redundant interface methods, for convenience or clarity e.g. `getSize()` vs. `isEmpty()`. Since closely related, if one already developed, test for the next may immediately pass.
    - (Action) To ensure both are covered in our testing, either:
        - Use a single helper or custom assert that verfies both internally, or...
        - Explicitly test the link between the two, and then only continue with one going forward.
- Wrote too much code in a previous iteration.
    - Breaking Rule 3 in turn breaks Rule 1. TDD falls apart; its benefits fade.
    - Incrementally build solution, using failing tests to justify growth.
    - (Action) Good to have foresight. Jot down notes. Will help guide solution.
    - Resisting overcoding keeps code simple; prevents permanent over-complexity.
    - Also ensures you don't omit tests (due to immediate passes) that would otherwise be valuable docs / specs.
- Are testing after-the-fact for added confidence.
    - When unsure how system handles certain cases, can write test to check its response.
    - (Action) If fails, follow normal TDD cycle. If passes, discard or keep new test, depending on docs value.

## Mindsets for Success

## Mechanics for Success
