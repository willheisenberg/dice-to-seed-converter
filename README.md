# Dice to Bitcoin Seed Converter

This program allows you to generate a Bitcoin seed using dice rolls. The program converts the rolls into a binary and hexadecimal representation, and then calculates the corresponding 24-word mnemonic using a wordlist.

## How It Works

This program requires 64 rolls of a 16-sided dice (or simulated dice rolls). The user enters each dice roll, and the program generates a 256-bit binary string from the rolls. This binary string is then converted into a SHA-256 hash. Finally, the program uses a predefined wordlist to convert the binary string into 24 words that can be used as a Bitcoin seed.

## Getting Started

To use this program, you will need:

1. **Dice:** It's recommended to get a few 16-sided dice to generate the necessary random numbers.
2. **Live Operating System:** For security reasons, it's highly recommended to run this program on a live Linux distribution, such as Debian Live. This ensures the system is not compromised by malware or other vulnerabilities.

## Usage Instructions

1. **Prepare:** Run the program on a secure, offline system. A live Debian distribution is a good choice.
2. **Roll Dice:** Roll a 16-sided dice 64 times. Alternatively, you can simulate the rolls using a random number generator.
3. **Input:** Enter each dice roll into the program. 
4. **Receive Seed:** The program will output a 24-word mnemonic representing your Bitcoin seed.
5. **Shutdown:** After using the program, immediately shut down the computer using the power button and erase the live distribution to minimize any potential risks.

## Security Note

The program should only be run on a secure, offline computer. This minimizes the risk of malware or unauthorized access compromising your Bitcoin seed.

## Disclaimer

**Use this program at your own risk. The author is not responsible for any lost or stolen coins.**

## Example

To run the program, compile it using g++, and execute it:

```bash
g++ -o dice_to_seed dice_to_seed.cpp -lcrypto
./dice_to_seed
```

Then, follow the on-screen prompts to input your dice rolls and generate the Bitcoin seed.
