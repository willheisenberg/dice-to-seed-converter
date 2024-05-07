# Dice to Bitcoin Seed Converter

This program allows you to generate a Bitcoin seed using dice rolls. The program converts the rolls into a
binary and hexadecimal representation, and then calculates the corresponding 24-word mnemonic using a
wordlist.

## How It Works

This program generates a Bitcoin seed from a series of dice rolls. The user inputs 64 rolls of a 16-sided
dice, each between 1 and 16, which the program converts into binary and hexadecimal representations using the
'toBinaryString' and 'toHexString' functions. Next, the program computes a SHA-256 hash of the hexadecimal
representation, using OpenSSL's EVP API. The resulting binary string, combined with the first 8 bits of the
hash, forms a 264-bit binary string. This string is then split into 24 groups of 11 bits each, which
correspond to indices in a predefined wordlist, creating a 24-word mnemonic. The program then displays the
mnemonic words to the user.

## Getting Started

To use this program, you will need:

1. **Dice:** It's recommended to get a few 16-sided dice to generate the necessary random numbers.
2. **Live Operating System:** For security reasons, it's highly recommended to run this program on a live
   Linux distribution, such as Debian Live. This ensures the system is not compromised by malware or other
   vulnerabilities.

## Requirements

- GCC (GNU Compiler Collection) or a similar C++ compiler
- OpenSSL development libraries (`libssl-dev` on Debian-based systems)

## Usage Instructions

1. **Prepare:** Run the program on a secure, offline system. A live Debian distribution is a good choice.
2. **Roll Dice:** Roll a 16-sided dice 64 times.
3. **Input:** Enter each dice roll into the program.
4. **Receive Seed:** The program will output a 24-word mnemonic representing your Bitcoin seed.
5. **Shutdown:** After using the program, shut down the computer using the power button and erase the live
   distribution to minimize any potential risks.

## Security Note

The program should only be run on a secure, offline computer. This minimizes the risk of malware or
unauthorized access compromising your Bitcoin seed.

## Disclaimer

**Use this program at your own risk. The author is not responsible for any lost or stolen coins.**

## Example

To run the program, compile it using g++, and execute it on a offline linux distribution:

```bash
g++ -o dice_to_seed dice_to_seed.cpp -lcrypto
./dice_to_seed
```

Then, follow the on-screen prompts to input your dice rolls and generate the Bitcoin seed.
