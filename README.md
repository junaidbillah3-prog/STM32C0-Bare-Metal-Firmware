# STM32C0-Bare-Metal-Firmware
focusing on Bitwise embedded systems while implemented some MISRA C compliance.

Hi, I am Junaid, I started this repository to learn Misra C compliance and Bare metal programming.

When I was working in VS Code i would often find myself somewhat annoyed of the fact that i could not really see or understand the "how?" or the "why?", so i tend to get curious and slowly i started reducing abstraction layers until i stumbled upon Misra C 2012.

It really improved the way I write my code and what i actually am intending instead of letting an abstraction layer hide the registers from me, so i decided why not try.

My first board was the STM32 Nucleo C031C6, i started learning about Clock Speeds and CPU cycles and learnt about RCC (reset clock control) and MODER (mode register) and 32 Bit masking and even modern methods like BSRR (Bit set reset register)

learning at a low level lets you use the intuition rather than mindlessly using functions which are not even meant for that purpose. One thing i learnt in embedded systems is that predictability of code matters more than writing convenience.

