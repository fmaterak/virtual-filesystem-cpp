# Virtual File System — C++23

A modular virtual file system implemented in modern **C++23**, featuring an interactive command-line interface (REPL), persistent JSON serialization, and unit-tested components.

## ✨ Features
- 🗂️ Create directories and files (`mkdir`, `touch`)
- 📁 Navigate directories (`cd`, `ls`, `pwd`)
- 📝 Edit file contents (`echo`, `cat`)
- 💾 Save and load the file system state (`save`, `load`)
- ✅ Unit-tested core modules (`Path`, `VFS`, `Serializer`)
- 🛠️ CMake-based project structure with separate `src/`, `include/`, and `tests/`

## 🧩 Modules Overview
- **VFS** — command interpreter and file system manager
- **Node**, **File**, **Directory** — in-memory representation of file system objects
- **Path** — path parsing and normalization
- **Serializer** — JSON serialization and deserialization (based on [nlohmann/json](https://github.com/nlohmann/json))

## 🚀 Build & Run

```bash
# Clone the repo
git clone https://github.com/yourusername/your-repo-name.git
cd your-repo-name

# Build the project
cmake -S . -B build
cmake --build build

# Run the app
./build/src/vfs_app

# Run tests
cd build
ctest --output-on-failure

🛠️ Requirements
C++23 compatible compiler (GCC 13+, Clang 17+, MSVC 2022)

CMake 3.20+

nlohmann/json (integrated via FetchContent or header)

📝 Example Usage
shell
> mkdir projects
> cd projects
> touch notes.txt
> echo "Initial project notes" > notes.txt
> cat notes.txt
> save fs.json
> exit
📑 License
MIT License