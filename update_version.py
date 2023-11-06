import re

def update_version(version):
    # Update the version in conanfile.py
    with open("conanfile.py", "r", encoding="utf-8") as f:
        conanfile = f.read()
    conanfile = re.sub(r"version = \"\d+\.\d+\.\d+\"", f"version = \"{version}\"", conanfile)
    with open("conanfile.py", "w", encoding="utf-8") as f:
        f.write(conanfile)

    # Update the version in README.md
    with open("README.md", "r", encoding="utf-8") as f:
        readme = f.read()
    readme = re.sub(r"\d+\.\d+\.\d+", f"{version}", readme)
    with open("README.md", "w", encoding="utf-8") as f:
        f.write(readme)

    # Update the version in CMakeLists.txt
    with open("CMakeLists.txt", "r", encoding="utf-8") as f:
        cmake = f.read()
    cmake = re.sub(r"project\(meltrix VERSION \d+\.\d+\.\d+ DESCRIPTION", f"project(meltrix VERSION {version} DESCRIPTION", cmake)
    with open("CMakeLists.txt", "w", encoding="utf-8") as f:
        f.write(cmake)

    # Update the version in docs/Doxyfile.in
    with open("docs/Doxyfile.in", "r", encoding="utf-8") as f:
        doxyfile = f.read()
    doxyfile = re.sub(r"PROJECT_NUMBER         = \d+\.\d+\.\d+", f"PROJECT_NUMBER         = {version}", doxyfile)
    with open("docs/Doxyfile.in", "w", encoding="utf-8") as f:
        f.write(doxyfile)

if __name__ == "__main__":
    import sys
    if len(sys.argv) != 2:
        print("Usage: python update_version.py <version>")
        sys.exit(1)
    update_version(sys.argv[1])