# CS200 Homework 2 - Completion Checklist

Use this checklist to ensure you've completed all requirements before submission.

---

## ✅ Core Requirements Checklist

### 📦 Setup & Configuration
- [x] Accept the assignment on GitHub Classroom
- [x] Download starter files and add them to your git repository
- [x] Update window title in `main.cpp` to include your name
- [ ] Add proper header comments to all modified files (author, course, term, DigiPen copyright)

---

### 🧩 Implementation Tasks
- [x] Complete `CreateVertexArrayObject()` function in `source/OpenGL/VertexArray.cpp`
- [x] Implement VAO creation using `gl::GenVertexArrays`
- [x] Implement VAO binding using `gl::BindVertexArray`
- [x] Handle multiple vertex buffers with different layouts
- [x] Support both integer and floating-point vertex attributes
- [x] Implement vertex attribute divisors for instanced rendering
- [x] Properly bind and unbind OpenGL state
- [x] Replace direct OpenGL calls with `gl::` wrappers in `source/CS200/RenderingAPI.cpp`
- [x] Implement OpenGL information logging (vendor, renderer, version, limits)
- [ ] Create custom demo class (e.g. `DemoMyModel.cpp` and `DemoMyModel.hpp`)
- [ ] Include demo header in `DemoVAO.cpp`
- [ ] Add demo files to CMake build system (`source/CMakeLists.txt`)
- [ ] Complete all TODO comments and remove them after implementation

---

### 🛠 Build & Testing
- [ ] Project builds successfully on **Windows x64**
- [ ] Project builds successfully on **Linux x64**
- [ ] Project builds successfully for **Web**
- [ ] Code compiles without warnings or errors
- [ ] `scan_build_project.py` script runs successfully
- [ ] Code is formatted using `clang-format`

---

### ⚙️ Functionality Verification
- [ ] VAO implementation handles multiple buffer configurations correctly
- [ ] OpenGL calls consistently use `gl::` wrapper functions
- [ ] OpenGL capabilities and settings are logged during initialization
- [ ] Custom demo visualizes a model of your own creation
- [ ] Demo demonstrates understanding of vertex buffer layouts
- [ ] Custom demo includes at least one ImGui control to modify the model
- [ ] Web version is interactive and functional

---

### 🌐 Web Deployment
- [ ] Create a Release Web build
- [ ] Host the web version online (recommended: GitHub Pages)
- [ ] Verify the hosted version works correctly

---

## 📤 Submission Requirements

### What to Submit
- [ ] **URL**: Submit the URL to your working Release Web version
- [ ] **Repository Snapshot**: Download ZIP archive from GitHub
- [ ] Remove unnecessary files (build folders, temp files, binaries)
- [ ] Ensure all source code and project files are included
- [ ] Verify `main` branch is up to date

---

### Pre-Submission Verification
- [ ] Web URL is accessible and demonstrates completed assignment
- [ ] ZIP file contains complete project structure
- [ ] All requirements from Core Requirements checklist are met
- [ ] No build artifacts or temporary files in submission

---

## 🎯 Grade Targets

### For C Grade (Minimum Passing)
- [ ] All Core Requirements completed

---

### For B Grade
- [ ] All Core Requirements completed
- [ ] Most Additional Requirements completed

---

### For A Grade
- [ ] All Core Requirements completed
- [ ] All Additional Requirements completed

---

### For S Grade (Exceeds Expectations)
- [ ] All A-grade requirements completed  
Plus implement advanced features such as:
- [ ] Multiple Model Creation (several different 2D models)
- [ ] Complex Geometry (curves, gradients, procedural patterns)
- [ ] Enhanced Graphics Debugging (buffer memory usage tracking)
- [ ] Interactive Model Editing (real-time vertex editing, color controls)
- [ ] Advanced Buffer Layouts (hybrid data organizations)
- [ ] Save/Load Models (file I/O for vertex data configurations)
