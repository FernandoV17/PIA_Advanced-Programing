
# PIA Advanced Programming – DNA Processing Project in C++

This project implements an efficient system for processing, sorting, and analyzing DNA sequences in C++, using advanced programming techniques such as parallelization with OpenMP. Additionally, it includes support for performance analysis with Python visualization scripts.

## 📘 Complete Documentation

View detailed project documentation on DeepWiki:
👉 [deepwiki.com/FernandoV17/PIA_Advanced-Programing/1-overview](https://deepwiki.com/FernandoV17/PIA_Advanced-Programing/1-overview)

## 📦 How to Clone and Use This Project

### 1. Clone the Repository
```bash
git clone https://github.com/FernandoV17/PIA_Advanced-Programing.git
cd PIA_Advanced-Programing
```

## ⚙️ Compilation and Execution (C++)

### 2. Compile with Make
Ensure `g++` with OpenMP support is installed.
```bash
make
```

### 3. Run the Program
```bash
./builds/main
```
- Ensure the input file `data/input/data.txt` exists.
- The program will generate sorted output in `data/output/data_sorted.txt`.

## 🐍 Additional Python Analysis

The project includes Python scripts for performance visualization.

### 4. Create a Python Virtual Environment (Optional)
```bash
python3 -m venv venv
source venv/bin/activate  # Windows: venv\Scripts\activate
```

### 5. Install Dependencies
```bash
pip install -r requirements.txt
```

### 6. Run Analysis Scripts
```bash
python scrips/analisis_tiempo.py
```

## 📂 Project Structure
```
PIA_Advanced-Programing/
├── cpp/
│   ├── main.cpp
│   └── lib/
│       ├── merge_sort/
│       │   ├── merge_sort.cpp
│       │   └── merge_sort.h
│       └── counting/
│           ├── counting.cpp
│           └── counting.h
├── builds/
├── scrips/
│   └── analisis_tiempo.py
├── data/
│   ├── input/
│   │   └── data.txt
│   └── output/
│       └── data_sorted.txt
├── execution_data.npz
├── Makefile
├── requirements.txt
└── README.md
```

## 🧪 Core Features
- ✔️ **Binary DNA Sequence Reading**
- ✔️ **Valid Nucleotide Counting** (A, T, C, G, U)
- ✔️ **Efficient Merge Sort**
- ✔️ **OpenMP Parallelization**
- ✔️ **Python Performance Visualization**

## 📌 Additional Notes
- Performance depends heavily on file I/O and sequence size.
- OpenMP parallelization offers modest improvements due to natural bottlenecks (e.g., mergeSort merging and counting synchronization).
- Code is designed for clarity, modularity, and extensibility.
```
