## directory content

**SIG_Hub.h**
```
class SIG_Hub implements I_SIG_Hub
```

**SIG_Provider.h**
```
class SIG_Provider implements I_SIG_Provider
```

**SIG_X.h**
```
classes SIG_(X) implement I_SIG

SIG_H  main signal without speed indicator
handles:
- H0
- H1

SIG_N  support signal with speed indicator
handles:
- N0
- N1
- speed

SIG_H_N  main signal and support signal with speed indicator
handles:
- H0 N0
- H0 N1
- H1 N0
- H1 N1
- speed
```
