# 🏨 Hotel Management System (Hotel-UI)

[![C++](https://img.shields.io/badge/Language-C%2B%2B17-blue.svg)](https://isocpp.org/)
[![Framework](https://img.shields.io/badge/Framework-Qt%206-green.svg)](https://www.qt.io/)
[![Platform](https://img.shields.io/badge/Platform-macOS%20%7C%20Windows%20%7C%20Linux-lightgrey.svg)](https://www.qt.io/)
[![Status](https://img.shields.io/badge/Status-Finalized%20(2026)-success.svg)]()

A clean, responsive desktop application for hotel reservation and customer management built with **C++** and **Qt**.

Originally developed during my **2nd semester** of university as an academic project demonstrating Object-Oriented Programming, data structures, and GUI development, subsequently refreshed and modernized.

---

## 📅 Project Timeline

| Milestone | Year | Description |
| :--- | :---: | :--- |
| **Initial Conception & Development** | **2024** | Built during **Term 2 (Sophomore year)** as a core C++/Qt academic project. |
| **First GitHub Release** | **2025** | Published to GitHub as open-source portfolio showcase. |
| **Refinement & Finalization** | **2026** | Complete UI overhaul: responsive centering layouts, Tab key navigation order, macOS/Qt 6 modern kit support, bug fixes, and dialog lifecycle management. |

---

## ✨ Features

- 👤 **Customer Management**:
  - Add new customers with personal details, contact information, and address.
  - View all registered customers in a clean, scrollable tabular view.
- 🛏️ **Room Management**:
  - Register new rooms with pricing, capacity, descriptions, and dynamic availability statuses (`Available` / `Reserved`).
  - Overview list of all rooms with real-time status tracking.
- 📝 **Reservation System**:
  - Book rooms for registered customers with duration calculation and final pricing.
  - View all active reservations with full details.
  - Cancel existing reservations with automatic status updates.
- 🎨 **Modern & Responsive UX**:
  - **Centered & Responsive Layouts**: Automatically centers dialogs, forms, tables, and buttons across any window dimension, screen resolution, or fullscreen mode.
  - **Sequential Tab Navigation**: Full keyboard navigation across all input fields and action buttons.
  - **Clean Window Lifecycle**: Main dashboard automatically hides when modal dialogs are open and smoothly restores on completion.
  - **Centralized Alerts**: All information and warning prompts (`QMessageBox`) appear centered relative to the active screen.

---

## 🛠️ Tech Stack & Requirements

- **Language**: C++ (C++11 / C++17 compatible)
- **GUI Framework**: Qt (Qt 5 or Qt 6, tested on Qt 6.10)
- **Build System**: qmake (`Hotel.pro`)
- **Supported OS**: macOS, Linux, Windows

---

## 🚀 Getting Started

### 1. Clone the Repository
```bash
git clone https://github.com/PooyaCheshmehkhavar/Hotel-UI.git
cd Hotel-UI/Hotel
```

### 2. Open with Qt Creator
1. Launch **Qt Creator**.
2. Select **File > Open File or Project...**
3. Choose `Hotel.pro` inside the `Hotel` directory.
4. Select your configured Kit (e.g., **Qt 6.x Desktop**).
5. Click **Configure Project**.

### 3. Build & Run
- Press `Cmd + R` (macOS) or `Ctrl + R` (Windows/Linux), or click the green **Run** button at the bottom left.

### Command-Line Build (Optional)
```bash
cd Hotel
qmake Hotel.pro
make
./Hotel.app/Contents/MacOS/Hotel   # On macOS
# or ./Hotel                       # On Linux
```

---

## 📂 Project Architecture

```text
Hotel-UI/
├── Hotel/
│   ├── Hotel.pro               # Project configuration file
│   ├── main.cpp                # Application entry point
│   ├── hotel.h / hotel.cpp     # Main dashboard controller
│   ├── hotel.ui                # Main dashboard UI
│   ├── centerhelper.h          # Screen centering & dialog helper utilities
│   ├── addcustomerform.*       # Add customer form
│   ├── viewcustomersform.*     # Customer listing & table view
│   ├── addnewroom.*            # Room registration form
│   ├── viewrooms.*             # Room directory & status table
│   ├── makereserve.*           # Reservation booking engine
│   ├── viewrev.*               # Reservation listing
│   └── cancelrev.*             # Reservation cancellation workflow
└── README.md
```

---

## 👨‍💻 Author

**Pooya Cheshmehkhavar**
- GitHub: [@PooyaCheshmehkhavar](https://github.com/PooyaCheshmehkhavar)

---

## 📄 License

This project is open-source and available under the [MIT License](LICENSE).
