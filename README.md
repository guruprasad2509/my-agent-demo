# my-agent-demo

## Overview

`my-agent-demo` is a hands‑on demonstration of building multi‑agent systems using the **my‑agent** framework. It showcases basic concepts such as creating agents, defining tools, orchestrating interactions, and handling user input.

## Features

- Simple multi‑agent architecture
- Example agents with clear responsibilities
- Demonstrates tool usage and message passing
- Easy to extend for custom scenarios

## Installation

```bash
# Clone the repository
git clone https://github.com/yourusername/my-agent-demo.git
cd my-agent-demo

# (Optional) Create a virtual environment
python -m venv venv
source venv/bin/activate  # On Windows use `venv\Scripts\activate`

# Install dependencies
pip install -r requirements.txt
```

## Usage

Run the demo script:

```bash
python demo.py
```

The script will start an interactive session where you can type queries and watch the agents collaborate to produce a response.

### Configuration

You can adjust the agents, tools, and prompts by editing the `demo.py` file. The code is heavily commented to guide you through each step.

## Contributing

Contributions are welcome! Please follow these steps:

1. Fork the repository.
2. Create a new branch for your feature or bug‑fix:
   ```bash
   git checkout -b feature/your-feature-name
   ```
3. Make your changes and ensure they pass any existing tests.
4. Commit your changes with a clear commit message.
5. Push to your fork and open a Pull Request against the `main` branch.

### Guidelines

- Keep code style consistent (PEP 8).
- Write clear docstrings for new functions/classes.
- Update the README or other docs when adding new features.
- Ensure the project builds and runs after your changes.

## License

This project is licensed under the MIT License – see the [LICENSE](LICENSE) file for details.
