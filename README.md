# The DSTW Project

## state of implementaion
<div style="background-color:#F8F8F8;">
<img src="specification/diagrams/overview.svg" alt="component overview">
</div>

## central error logging
There is no error handling in the individual components.
All errors are reported to the central error log.
Further error handling / reactions / statistics will be implemented here.
<div style="background-color:#F8F8F8;">
<img src="specification/diagrams/log.svg" alt="central logging">
</div>


## test setup
Due to the Interface Locator (IL) any application component instance can be replaced by a mock instance.
Sample: test setup for Dispatcher component 
<div style="background-color:#F8F8F8;">
<img src="specification/diagrams/test_dispatcher.svg" alt="test of Dispatcher">
</div>

## code coverage
for current current code coverage see [coverage.md](testing/coverage.md)

