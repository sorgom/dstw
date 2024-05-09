# AI usage experience
## github copilot
I used the 30 days trial period of github copilot with VS code to find out how effectively copilot enhances / speeds up development.

Github copilot made a mixed impression from extremely helpful to completely annoying.

Sometimes it really worked:
- just type a word - comment or code
- copilot proposes just what was intended or even better
- just a TAB and code is written

Sometimes it didn't
- proposals where completely unusable
- the occupation of TAB can confuse

Copilot worked as good with python as with C++.

Since it is AI - it learns as you work with it and .. gets better.

### conclusion

Once I've got used to it (and it to me), it pulverizes the typing work.

And yes: I pay the 10$ / month.

## ChatGPT
Later in the development - just for curiosity - I asked ChatGPT for a solutions.

### sample: .sh to .cmd
#### linux
I had written a linux shell script (.sh) to run system tests:
- run DSTW application in background
- run test application
- run stop application (which send a stop telegram to DSTW application)

No big deal in bash.

#### win
Since everything also build in VS - there wa a need to have this as a Windows cmd script.

For me the Windows scripting syntax is a pain in the ass.

#### translate
So I came to the idea to ask ChatGPT:
- copied the .sh code to ChatGPT
- asked: can you translate to cmd?
- and I got it, not yet working, but almost

#### discuss
The thing is, that you really get to better solutions by discussion.

e.g.
- me: I don't think "call" statements are correct, because they exit the script
- GPT: sorry, you are right
- new code
- took 10 minutes to have the working code

Have a look at the results if you like:
-   [source](make/runSystemTests.sh)
-   [translation](make/runSystemTests.cmd) 

### conclusion
ChatGPT is a boost. It will make google and sites like StackOverflow more or less redundant.

(The price of this is a consumption of electric energy equivalent to a town with 150000 - yes: a hundred and fifty thousand - inhabitants.)

## AI conclusion
AI has changed the approach to software development
- less work with implementation issues
- more concentration on issues like
    - subject
    - requirements
    - collaboration
