# release plan

# release 2023-11 _Maggie_
-   framing
    -   fictive telegram structures

## application   
-   system
    -   Dispatcher
    -   Loader (for site specific data, _Projektierung_)
-   subsytem TSW (track switches)
    -   TSW
    -   TSW Provider
    -   TSW Hub
-   subsytem SIG (signals)
    -   SIG_X
    -   SIG Provider
    -   SIG Hub

### system
#### Dispatcher
-   full functionality for TSW, SIG
    -   register elment positions from subsytem _Hubs_
    -   distibute incomming telegrams to subsytem _Hubs_
        -   from field
        -   from GUI
#### Loader
-   full functionality for TSW, SIG
    -   distribute data to subsytem _Providers_
#### subsytem TSW
-   TSW element
    -   commands from GUI: WU, left, right
    -   commands to field
    -   states from field
    -   states to GUI 
    -   correct state processing
-   TSW Provider
    -   full functionality
        -   load site specific data, _Projektierung_
        -   register element positions at _Dispatcher_
        -   provide elements to _TSW Hub_
-   TSW Hub
    -   full functionality
        -   forward telegrams to elements at _TSW Provider_
            -   from field
            -   from GUI
        -   forward commands from elements as telegrams
            -   to field
            -   to GUI




