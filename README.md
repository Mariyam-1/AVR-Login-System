# 🔐 AVR-Based Password-Protected Door Lock System

This project is an embedded system implementation of a **secure door lock** using an **AVR microcontroller**. The system allows users to set a 5-digit password, confirm it, and then control the locking mechanism through a DC motor. The system handles authentication with limited retries, alerts on failure, and includes external interrupt handling.

---

## 📦 Folder Contents

### 🔹 APP/
- `main.c`  
  Contains the main application logic (login handling, password setting, and motor control).

### 🔹 HAL/ (Hardware Abstraction Layer)
- `LCD.*`, `KEYPAD.*`, `LED.*`, `Buzzer.*`, `Motor.*`  
  Drivers for external components like LCD, Keypad, LEDs, Buzzer, and DC Motor.

### 🔹 MCAL/ (Microcontroller Abstraction Layer)
- `DIO.*`, `Interrupt.*`, `Timer0_*.*`  
  Drivers for microcontroller core functionalities such as I/O pins, external interrupts, and Timer0.

### 🔹 LIB/
- `BitMath.h`  
  Macros for bit manipulation (SET_BIT, CLR_BIT, etc).
- `STD.h`  
  Common typedefs like `u8`, `u16`, `u32`, and standard macros.

---

## ⚙️ System Components

- **LCD (16x2)**: For user interface and messages.
- **Keypad (4x4)**: To input passwords and commands.
- **LEDs**: Indicate different states (lock/unlock/error/interrupt).
- **DC Motor**: Simulates door opening/closing.
- **Buzzer**: Alerts on password failure.
- **Timers**: Control delays and time-based operations.
- **External Interrupt (INT0)**: Emergency stop/reset requiring re-authentication.

---

## ✅ Features

-  **5-Digit Password Setup & Verification**
-  **Three Attempts Before Lockdown**
-  **Motor-Driven Door Operation**
  - 15s Open → 3s Hold → 15s Close
-  **Buzzer Alert** after 3 failed trials
-  **Interrupt Handling** for real-time security reset
-  **All Drivers Implemented from Scratch**

---

## 🧪 How It Works

1. On startup, user sets a 5-digit password.
2. System asks to re-enter the password for confirmation.
3. After confirmation:
   - `+` opens the door (requires correct password).
   - `-` allows changing the password.
4. Three wrong attempts trigger a **10s lockout** with buzzer.
5. Interrupt (INT0) can trigger emergency access, asking for password again.

---

##  Built With

- **AVR ATmega32**
- **AVR-GCC (C language)**
- **Proteus / Atmel Studio / Microchip Studio** (for simulation/debugging)
![Simulation](https://github.com/user-attachments/assets/711d5b46-a7db-4069-9085-49d74fe90201)

  ---
## 🔌 Proteus Simulation

Here is the simulation setup for the login system in Proteus:

<p align="center">
  <img src="[Uploading Simulation.png…]()" alt="Proteus Simulation" width="600px" style="border-radius: 12px;" />
</p>



---




