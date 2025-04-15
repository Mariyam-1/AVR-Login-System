# 🔐 AVR-Based Password-Protected Door Lock System

This project is an embedded system implementation of a **secure door lock** using an **AVR microcontroller**. The system allows users to set a 5-digit password, confirm it, and then control the locking mechanism through a DC motor. The system handles authentication with limited retries, alerts on failure, and includes external interrupt handling.

---

## 📁 File Structure
avr-login-system/
├── APP/
│   └── main.c
├── HAL/
│   ├── LCD.h
│   ├── LCD_TYPES.h
│   ├── KEYPAD.h
│   ├── LED.h
│   ├── Buzzer.h
│   └── Motor.h
│   ├── LCD.c
│   ├── KEYPAD.c
│   ├── LED.c
│   ├── Buzzer.c
│   └── Motor.c
├── MCAL/
│   ├── DIO.h
│   ├── Interrupt.h
│   ├── Timer0_confg.h
│   ├── timer0_interface.h
│   ├── Timer0_Private.h
│   ├── DIO.c
│   ├── Interrupt.c
│   ├── Timer0_programe.c
├── LIB/
│   ├── BitMath.h
│   └── STD.h

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

- 🛡️ **5-Digit Password Setup & Verification**
- 🔁 **Three Attempts Before Lockdown**
- 🔐 **Motor-Driven Door Operation**
  - 15s Open → 3s Hold → 15s Close
- 🚨 **Buzzer Alert** after 3 failed trials
- ⚡ **Interrupt Handling** for real-time security reset
- 🧠 **All Drivers Implemented from Scratch**

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

## 🚧 Built With

- **AVR ATmega32**
- **AVR-GCC (C language)**
- **Proteus / Atmel Studio / Microchip Studio** (for simulation/debugging)

---




