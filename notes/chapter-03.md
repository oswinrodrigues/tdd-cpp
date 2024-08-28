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

## Three Rules

## 'Green On Red'

## Mindsets for Success

## Mechanics for Success
