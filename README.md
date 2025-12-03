# 📚 Programmazione di Sistemi Multicore – Translated Notes & Code

## ⭐ About this Repository

This repository contains translated lecture notes and codes for the **"Programmazione di Sistemi Multicore"** course, taught by **Professor De Sensi** as part of the **Bachelor of Science in Informatica** at **Sapienza Università di Roma**.

---

## 📍 Course Details

- **📅 Lecture Schedule:**
  - **Tuesdays:** 17:00 – 19:00 at *Aula Magna, Regina Elena*.
  - **Wednesdays:** 14:00 – 17:00 at *Aula 11, Via Scarpa, Engineering Department*.

- **🧪 Exam Structure:**
  - A project and an oral exam covering both the project and the theoretical topics discussed throughout the lectures.

---

## 🚨 Executing Codes in Linux

The Professor uses Linux as the main terminal/compiler for the course.

If you are not familiar with it, here are some instructions for running a C file in a Linux environment:

1) `gcc [filename].c -o [filename]`: use this command to *compile and name the executable file (this also comes in handy to avoid ambiguities)*.
2) `./[filename]`: use this command to *run the executable file*.
3) `rm [filename]`: if needed, use this command to *delete the executable file*.

However, some APIs use different instructions for running these files:

- 📮 **OpenMPI**
  1) `mpicc -g -Wall -o [filename] [filename].c`: use this command to *compile the executable file*.
  2) `mpiexec -n [processes] ./[filename]`: use this command to *run the executable file* or, by adding `ddd`, to *debug the program*.
- 🐌 **PThreads**
  
  Use the `pthread_create()` function to *start the threads in the executable file*.
- 🧭 **OpenMP**
  1) ` gcc -g -Wall -fopenmp -o [filename] [filename].c`: use this command to *compile the executable file* in OpenMP.
  2) `./[filename] n`: use this command to *run the executable file* using *n threads*.

     **N.B.:** The scheduling order of the threads is non-deterministic.
- 🛰 **CUDA**
  1) `nvcc --arch=sm_20 [filename].cu --o [filename]`: use this command to *compile the executable file* using CC 2.0.
  2) `./[filename]`: use this command to *run the executable file*.

     **N.B.:** For formality, programs containing CUDA codes are characterized by the `.cu` extension.

     **N.B.:** If your laptop does not support CUDA GPUs, you can ask the Professor to give you access to a University cluster (refer to the form shown on the November 25 lecture) or run CUDA using Google Colab (refer to last year's materials).

---

## 🎬 Additional Information

- 📌 For official communications and course materials, please refer to the Moodle page of the course.
- 📩 For any questions or clarifications, feel free to contact me directly.
- 📈 The Professor will use a GitHub classroom to handle the exercises, which will be pushed and graded according to their correctness.

  **N.B.:** For this year, the grades of the exercises will **not** impact the final grade of the exam.

---

## 📖 Course Log
**23 September:** Introduction to the course and to **parallel computing**.

**24 September:** Introduction to the C programming language: **variables, operators, input/output activities, selective branches, iterative branches, arrays, strings, functions, pointers**.

~~**30 September:**~~ This lecture was cancelled.

**1 October:** Introduction to the C programming language: **memory allocation, structs, lists**.

**7 October:** Recap on the **von Neumann architecture** and introduction to **MPI**.

**8 October**: **Message matching** and **communication modes** in MPI.

~~**14 October:**~~ This lecture was cancelled.

~~**15 October:**~~ This lecture was cancelled.

**21 October:** **Parallel design strategies** (GPLS, GSLP) and **collective communication** in MPI.

**22 October:** Exercises on MPI and evaluation of parallel programming: **speed-up**, **efficiency** and **scalability**.

**28 October:** Estimating speed-up using **Amdahl's law** and **Gustafson's law**.

**29 October:** Exercises on MPI and recap of **PThreads**.

~~**4 November:**~~ This lecture was cancelled.

~~**5 November:**~~ This lecture was cancelled.

**11 November:** Introduction to the **OpenMP** API: **pragmas and clauses, variable scope and reductions**.

**12 November:** Exercises and **parallel for loops**.

~~**18 November:**~~ This lecture was cancelled.

~~**19 November:**~~ This lecture was cancelled.

**25 November:** Introduction to **CUDA**.

**26 November:** Recap on **thread scheduling in CUDA** and **memory hierarchies**.

***1 December:** Extra lecture on profiling for bottlenecks in high-performance computers*.

**2 December:** Recap on **OpenMP** and introduction to **synchronization constructs** and **data dependencies**.

**3 December:** Recap of **data dependencies** for parallel loops.

**9 December:** TBA

**10 December:** TBA

**16 December:** TBA

**17 December:** TBA

---
