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

## 'Green On Red'

## Mindsets for Success

## Mechanics for Success
