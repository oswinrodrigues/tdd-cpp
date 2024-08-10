# TDD: A First Example

## Nomenclature

- "System" is the end product we want to develop with software
- "CUT" is Code Under Test, or the "production code" of the system
- "Behaviour" is a specific system functionality required by the specs

## Method

- Three rules of TDD, from 'Uncle Bob' (Robert C. Martin)
    - Write production code only to make a failing test pass.
    - Write no more of a unit test than sufficient to fail. Includes compilation failures.
    - Write only the production code needed to pass the one failing test.
- Incremental. One behaviour at a time, one test at a time.
    - Which remaining behaviour to 'test drive' next? The simplest one - straightforward, small.
    - Don't need all tests figured out right from the start.
- Can record thoughts about upcoming behaviours or tests in a 'test list'.
    - Reminders for later cleanup or refactor also go here.
    - A personal memo, a rough note, a thought-dumping ground. Does not constrain what you do and when you do it.
- Tests declare the behaviours your system should have.
    - Tests can be seen as specs. In fact, if crafted well, tests can be more concrete and comprehensive than specs.
    - Tests can be seen as documentation, expressing clearly how the CUT is designed, how it's to be used, etc.
- Converse: any behaviour present in the CUT that is not (yet) required by a test is bad.
    - At each iteration, the CUT should only have the simplest generalized solution for what the set of tests (so far) needs.
    - This philosophy necessitates adding behaviour that is only partial, or trivial, or even in breach of other specs.
- As we write more tests for more behaviours, this will automatically self-correct then.
    - Think of TDD as if only one spec is being revealed at a time.
    - Building incrementally, but with "continually verified, forward progress".
    - TDD makes such progress possible in the face of incomplete or new information.
    - After adding a new test and behaviour, a previous test may fail. This is good and part of the self-correction.
- Increases speed in long run, avoiding errors from large, complex changes.
    - Easy to debug when you know precisely what new code caused the failure. Root cause is exposed as soon as you create it.
    - Seek immediate, incremental feedback. Test early, often. Makes for safe coding.
    - Trade-off. Sometimes writing whole test clarifies interface design.
- We make decisions on design and implementation as we add tests.
- TDD is not a science, it is a craft.
    - It is honed by repeated practice. DO this with katas (section 11.5).
- TDD produces software that:
    - The customer wants. Tests concretely show specs are met.
        - Even for performance. TDD delivers the _requested_ performance and minimizes the cost of _over_-optimization
    - Works. Tests concretely show expected functionality.
        - Not silver bullet. Still susceptible to bugs, only fewer and less critical.
        - Still need other forms of after-the-fact testing (vs. before-the-fact test-driving).
    - Is written well. Less time spent trying to understand.
        - Makes refactoring safe and easy, as mentioned below. Low barrier to cleaning up mess.
        - Also because tests serve as documentation for the CUT, as mentioned above.
    - Is designed well. Meaning it's easily changed.
        - Easy changeability is both a result of an aid towards better design quality.
        - CUT's testability forces it to be designed with SOLID principles and other design best practices.

## Red

- Negative feedback (test failure) is good. Ensures test honesty.
    - Sometimes, a new test can pass with no change to the CUT, giving 'green' in the 'red' stage.
    - This may point to a poor test. False positives - tests passing when they shouldn't - mean dishonest tests.
    - Or, if the test is right, this may point to a poor TDD technique: taking too big (not incremental or minimal enough) steps in previous TDD cycles.

## Green

- Commit every time the 'code is green'. Known good states to roll back, if desired.
- Each cycle, we want to make 'green' by generalizing the solution.
    - But don't over-generalize. Don't account for future concerns.
- Be at peace with messy code. TDD saves a time and place to refactor _later_.
    - Defer complexity that slows you down.
    - For example, put a new class and its test in same file. The interface design will keep changing as you test-drive.
- Sometimes, in the 'red' or 'green' stage, a refactor of test infrastructure or CUT design (respectively) would help.
    - Keep the TDD cycle stages distinct. Do only one thing at a time.
    - In this case, stash the changes from the stage you were in, do the refactor, then come back.
- Tip: don't have to make green in one go:
    - Start with "declaration of intent". The solution's _what_. With unimplemented placeholders.
    - Then follow with implementing the needful. The solution's _how_.

## Refactor

- Don't neglect or postpone the "refactor" stage.
    - Do it before the small messes add up and make any cleanup arduous.
    - Sometimes, can defer a cleanup if you know the next test will 'drive' it out. But must guarantee that next step; make a note in the 'test list'.
- Retain existing behaviour (as shown by the test) while improving design.
    - Very satisfying to simplify (or completely eliminate) code, but only when we have confidence it won't break things. Our tests provide that confidence.
- Some examples of refactoring:
    - Eliminate hardcoding and code duplication
    - Enhance test abstraction and expressiveness
    - Make the CUT declarative and intention-revealing
        - "Declarative" separates interface (what) from implementation (how). Clear, readable code. Clean, scalable designs.
    - Ensure functions follow Single-Responsibility Principle (SRP) from SOLID
        - Function should have only one reason to change: either due to a change in policy (what) or implementation (how).
        - In other words, a function should not be concerned with both, policy and implementation.
- Don't make many refactoring changes at once. Follow TDD's incremental style. Verify each change with passing tests.
- Avoid prematurely optimizing during refactor (or green) stage.
    - Focus on correct behaviour, good design, consistent interfaces, expressive code.
    - Later, maybe, we optimize. But not without first measuring.

## Tests

- Test names must be expressive. A sentence on what the test verifies.
    - Same goes for 'assert' statements in tests.
- Tests must be independent.
    - Each test has its own separate context e.g. instance of object-under-test.
    - Each test deals with one precise behaviour. Even if two tests end up doing the same steps!
- Place common setup or teardown in test 'fixture' or 'suite'
    - Keeps individual tests focused and clean. Highly abstracted, highly expressive.
    - Facilitates future maintenance by restricting potential changes to one place.
    - But common setup must re-run in each test. Recall: each test has independent context.
- Strive for one assert per test (in general)
    - Focus on the behaviour under test, not the implementing function
    - A distinct behaviour deserves a separate test entirely
    - Rarely, can add a second assert, as a distinct case for the same test (behaviour), but only if it increases understanding of the behaviour.
- Implicit premises can be made more direct with precondition asserts.
    - Use sparingly. Often, meaningful naming is simpler and just as effective.
    - Sometimes, other tests already confirm said preconditions. But also better to be explicit. Use judgement.
- Some tests don't care about absolute values, just relative. Remember, tests validate behaviour not values.
    - e.g. checking that two differnet inputs result in the same output. Don't care what that output itself is.

## Tips

- When to stop writing test cases for the same behaviour?
    - Remember: we are test-driving, not testing.
    - "Testing" is concerned with exhaustively covering the specification.
    - "Test-driving" drives design and implementation. In TDD, we write tests just to specify or describe _the next_ behaviour needed.
    - If the logic won't change anymore, can stop writing tests for that particular behaviour.
- If we write only the minimal code to satisfy the spec-ed logic, when to consider unspecified behaviours e.g. unexpected inputs?
    - Good TDD that produces robust software will think about critical concerns beyond the explicit, limited specs.
    - But don't have to fix it right then and there. Can make a note in the 'test list'.
    - Or can pause and handle it right away, but in a separate TDD cycle, with a separate test.
- Answers to questions about unspecified behaviours are not always clear or known. Ask the customer.
    - One benefit of TDD is that it immediately documents the decision (via a test)
    - So no analysis time is wasted in the future to decipher how the CUT handles an edge case
- Thinking about unspecified behaviours may prod you to revisit a previous test
    - To account for the unspecified behaviour and see if the test passes. This goes beyond TDD to testing after-the-fact.
    - If passes, can keep modification to explicitly document the unspecified behaviour. Or can discard if deemed unnecessary.
- In after-the-fact testing, if passes immediately and you were unsure it would, might want to revisit the relevant system code
- Sometimes, test needs a function that a real-world user (of the system) won't. Make publicly accessible?
    - Okay to _selectively_ broaden the public interface of the system. After all, test _is also_ a client of the system.
    - Especially if it trades off low risk (unlikely + harmless) with high reward (saved time + sanity) for future readers.
