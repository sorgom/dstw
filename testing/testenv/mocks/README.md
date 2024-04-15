## directory content

#### M_Base.h
```
base class for mocks
```

#### M_Com.h
```
mock for interface I_Com
```

#### M_Dispatcher.h
```
mock for interface Dispatcher
```

#### M_Hub.h
```
common mock for all Hub interfaces
- I_TSW_Hub
- I_SIG_Hub
- I_LCR_Hub
```

#### M_Instances.h
```
mock instances (for IL)
for interface I_<NAME>
- function m_<NAME>() returns mock instance
- function mock_<NAME>() plugs mock instance into IL
```

#### M_LCR.h
```
mock for interface LCR
```

#### M_Log.h
```
mock for interface Log
```

#### M_Provider.h
```
common mock for all Provider interfaces
- I_TSW_Provider
- I_SIG_Provider
- I_LCR_Provider
```

#### M_SIG.h
```
mock for interface SIG
```

#### M_TSW.h
```
mock for interface TSW
```
