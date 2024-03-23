# TDD with CPP
Practice exercises from [the book](https://pragprog.com/titles/lotdd/) by [@jlangr](https://github.com/jlangr).


## Setup

1. Install [Dev Containers](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-containers) for VS Code
2. Fork this repository [on GitHub](https://docs.github.com/en/pull-requests/collaborating-with-pull-requests/working-with-forks/fork-a-repo#forking-a-repository)
3. Open the fork [in a container volume on VS Code](https://code.visualstudio.com/docs/devcontainers/containers#_quick-start-open-a-git-repository-or-github-pr-in-an-isolated-container-volume)
4. Wait for the container to be created (this is only necessary the first time)

## Workflow

This repository uses the [CMake Tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools) extension to build, test and debug.

### Build
Any of the following should work:
- Press `F7`
- Select `CMake: Build` from the [Command Palette](https://code.visualstudio.com/docs/getstarted/tips-and-tricks#_command-palette)
- Click `Build` button, beside `Build` heading, under `CMake` tab, in sidebar

### Test
Any of the following should work:
- Select `CMake: Run Tests` from the [Command Palette](https://code.visualstudio.com/docs/getstarted/tips-and-tricks#_command-palette)
- Click `Run Tests`, beside `Test` heading, under `CMake` tab, in sidebar
- Run `ctest` in terminal, while in `out/build/default/`

Alternate options not directly related to `CMake` are:
- Click `Run Test`, beside or below `tdd-cpp`, under `Testing` tab, in sidebar
- Run the test executable in terminal e.g. `.out/build/default/dummy_test`

### Debug
(To be added)
