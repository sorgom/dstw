# The model driven approach
## the plan
I happened to work for a project by the Clinch* that had (maybe still has) the following plan:
-	develop software for a digital interlocking from the scratch.
-	development should be model based.
-	use the IMB* toolchain including the Raggedy* modeling tool.

## SIL4
Security Integrity Level 4 requires following some rules, e.g.:

Before code can be checked in into a main branch it has to 
-	be peer reviewed.
-	be (module) tested successfully with a 100% code coverage
-	follow special coding guidelines (static code analysis, SCA)

Any check in / merge must be blocked before continuous integration has been passed successfully:
-	build
-	tests
-	coverage
-	SCA

## IMB toolchain
The IMB toolchain consists of 4 (four) so called managements that hardly collaborate with each other.

What the tools don’t provide is: 
-	a working source control
-	a working review facility
-	a continuous integration

What they provide is:
-	the permanent need of workarounds and repetitive click surface work down
-	a great collection of pitfalls and error driven frustration
-	permanent dysfunction
-	a high demand on support by specialists
-	crappy C-code in bits and pieces
-   90 % of the effort spent for the tools and not for work to be done

In other words: there is no way to reach SIL4 using the IMB toolchain.

## the result
If a company’s philosophy is never to report any problems, it ends up exactly like Clinch:
-	increasing demand of human resources without any improvement / acceleration of work done
-	increasing frustration of the ones that need to get the work done
-	a complete illusory estimation of progress by the management

*) names changed
