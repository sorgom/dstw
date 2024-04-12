# DSTW
## the project
An implementation of an interlocking control logic (ICL) which represents the states of field elements like signals or track switches and communicates with control panels (GUIs) and the real field elements.

It consists of the following components:
- TSW: track switches
- SIG: signals
- LCR: level crossings
- SEG: track segments
- SYS: commonly used system

The project does not intend an implementation that would work in a real digital interlocking (DSTW).

The aim is to apply and demonstrate techniques to meet security integrity level 4 (SIL4).

It shows a completely different approach than the [model driven](Clinch.md) one I happened to experience.

## components interaction overview
![overview](specification/doc/rel-2023-12_overview.svg)

## topics
- [SIL4](SIL4.md)
- [testing](testing/README.md)
- [code coverage](testing/coverage.md)
- [how to build](make/howto_build.md)
- [current lines of code](CLOC.md)
