# transition tables

## sample: transitions TSW
<div style="background-color:#F8F8F8;">
<img src="SC_TSW.svg" alt="SC TSW">
</div>

## valid transitions

```
The track switch (TSW) has only 6 different states.
State information from field can cause any transition,
except transitions to WAIT states.

thats adds up to
all transitions: 6 X 6
minus 6 transitions A -> A
minus 5 transitions to WAIT LEFT
minus 5 transitions to WAIT RIGHT
= 20

CMD LEFT  possible from UNDEF, RIGHT, WAIT RIGHT
CMD RIGHT possible from UNDEF, LEFT, WAIT LEFT
+ 6
CMD WU possible from LEFT, RIGHT
+ 2
= 28 valid transitions
```
This requires 28 test steps.

## events causing no transition

But we do not only want to _test all events that cause transition_.

We also want to _test all events that cause no transition_.

And also we want to have _as few test steps as possible_.

That means to generate sequences of test steps using the result state of the preceding steps.

This is done by script.

## extraction from state chart
First approach was to extract the transitions / events from the state chart.

StarUML for instance writes json format files that are easy to parse.

For the TSW states that works quite well.

## transition tables
The problem begins when there's _more than a few states_.

-   It is hardly possible to _draw_ the state chart without losing the overview.
-   It is hardly possible to _review_ the state chart without losing the overview.

That's why transition tables were introduced:

Simple small csv files describing the possible transitions.

Sample: transitions TSW

|FLD *||CMD LEFT||CMD RIGHT||CMD WU||CMD WU||
|:---|:---|:---|:---|:---|:---|:---|:---|:---|:---|
|UNDEF|UNDEF|UNDEF|WAIT LEFT|UNDEF|WAIT RIGHT||WAIT RIGHT||WAIT LEFT|
|DEFECT|LEFT|||||||||
|LEFT|RIGHT|||LEFT||LEFT||||
|RIGHT|DEFECT|RIGHT||||||RIGHT||
|WAIT LEFT||||WAIT LEFT||||||
|WAIT RIGHT||WAIT RIGHT||||||||

## test steps

It's a little script effort to generate all required test steps from the transition table.

Sample: test steps for TSW

|STEP|FROM|TO|EVENT|GLUE|
|---:|:---|:---|:---|:---|
|1|UNDEF|LEFT|FLD LEFT|
|2|||CMD LEFT|
|3|||FLD LEFT|
|4|LEFT|UNDEF|FLD UNDEF|
|5|||CMD WU|
|6|||FLD UNDEF|
|7|UNDEF|RIGHT|FLD RIGHT|
|8|||CMD RIGHT|
|9|||FLD RIGHT|
|10|RIGHT|UNDEF|FLD UNDEF|
|11|UNDEF|DEFECT|FLD DEFECT|
|12|||CMD LEFT|
|13|||CMD RIGHT|
|14|||CMD WU|
|15|||FLD DEFECT|
|16|DEFECT|UNDEF|FLD UNDEF|
|17|UNDEF|WAIT LEFT|CMD LEFT|
|18|||CMD LEFT|
|19|||CMD WU|
|20|WAIT LEFT|UNDEF|FLD UNDEF|
|21|UNDEF|WAIT RIGHT|CMD RIGHT|
|22|||CMD RIGHT|
|23|||CMD WU|
|24|WAIT RIGHT|UNDEF|FLD UNDEF|
|25|UNDEF|DEFECT|FLD DEFECT|*|
|26|DEFECT|LEFT|FLD LEFT|
|27|LEFT|RIGHT|FLD RIGHT|
|28|RIGHT|LEFT|FLD LEFT|
|29|LEFT|DEFECT|FLD DEFECT|
|30|DEFECT|RIGHT|FLD RIGHT|
|31|RIGHT|DEFECT|FLD DEFECT|
|32|DEFECT|UNDEF|FLD UNDEF|*|
|33|UNDEF|WAIT LEFT|CMD LEFT|*|
|34|WAIT LEFT|LEFT|FLD LEFT|
|35|LEFT|WAIT RIGHT|CMD RIGHT|
|36|WAIT RIGHT|LEFT|FLD LEFT|
|37|LEFT|WAIT RIGHT|CMD WU|
|38|WAIT RIGHT|RIGHT|FLD RIGHT|
|39|RIGHT|WAIT LEFT|CMD LEFT|
|40|WAIT LEFT|RIGHT|FLD RIGHT|
|41|RIGHT|WAIT LEFT|CMD WU|
|42|WAIT LEFT|DEFECT|FLD DEFECT|
|43|DEFECT|UNDEF|FLD UNDEF|*|
|44|UNDEF|WAIT RIGHT|CMD RIGHT|*|
|45|WAIT RIGHT|DEFECT|FLD DEFECT|
|46|DEFECT|UNDEF|FLD UNDEF|*|
|47|UNDEF|WAIT RIGHT|CMD RIGHT|*|
|48|WAIT RIGHT|WAIT LEFT|CMD LEFT|
|49|WAIT LEFT|WAIT RIGHT|CMD RIGHT|

The * GLUE field indicates that we have repeated transitions that are necessary to provide the entry state for the next test steps.

## test code

From here it's a last step to generate the test code using a template.

Sample: test template json file for TSW

```json
{
    "//" : "=================================",
    "//" : "transitions test code for TSW",
    "//" : "=================================",
    "prefixState": "TSW_STATE",
    "prefixCmd": "TSW_GUI_GMD",
    "cmd1": "CMD(_CMD_, _FLD_, _GUI_);",
    "cmd0": "CMD(_CMD_);",
    "fld1": "FLD(_VAL_, _VAL_);",
    "fld0": "FLD(_VAL_);",
    "csv": "specification/doc/transitions_TSW.csv"
}
```
Sample: generated test code for TSW

```cpp
        STEP(1)
        FLD(TSW_STATE_LEFT, TSW_STATE_LEFT);
        STEP(2)
        CMD(TSW_GUI_GMD_LEFT);
        STEP(3)
        FLD(TSW_STATE_LEFT);
        STEP(4)
        FLD(TSW_STATE_UNDEF, TSW_STATE_UNDEF);
        STEP(5)
        CMD(TSW_GUI_GMD_WU);
        STEP(6)
        FLD(TSW_STATE_UNDEF);
        STEP(7)
        FLD(TSW_STATE_RIGHT, TSW_STATE_RIGHT);
        STEP(8)
        CMD(TSW_GUI_GMD_RIGHT);
        STEP(9)
        FLD(TSW_STATE_RIGHT);
        STEP(10)
        FLD(TSW_STATE_UNDEF, TSW_STATE_UNDEF);
        STEP(11)
        FLD(TSW_STATE_DEFECT, TSW_STATE_DEFECT);
        STEP(12)
        CMD(TSW_GUI_GMD_LEFT);
        STEP(13)
        CMD(TSW_GUI_GMD_RIGHT);
        STEP(14)
        CMD(TSW_GUI_GMD_WU);
        STEP(15)
        FLD(TSW_STATE_DEFECT);
        STEP(16)
        FLD(TSW_STATE_UNDEF, TSW_STATE_UNDEF);
        STEP(17)
        CMD(TSW_GUI_GMD_LEFT, TSW_STATE_LEFT, TSW_STATE_WAIT_LEFT);
        STEP(18)
        CMD(TSW_GUI_GMD_LEFT);
        STEP(19)
        CMD(TSW_GUI_GMD_WU);
        STEP(20)
        FLD(TSW_STATE_UNDEF, TSW_STATE_UNDEF);
        STEP(21)
        CMD(TSW_GUI_GMD_RIGHT, TSW_STATE_RIGHT, TSW_STATE_WAIT_RIGHT);
        STEP(22)
        CMD(TSW_GUI_GMD_RIGHT);
        STEP(23)
        CMD(TSW_GUI_GMD_WU);
        STEP(24)
        FLD(TSW_STATE_UNDEF, TSW_STATE_UNDEF);
        STEP(25)
        FLD(TSW_STATE_DEFECT, TSW_STATE_DEFECT);
        STEP(26)
        FLD(TSW_STATE_LEFT, TSW_STATE_LEFT);
        STEP(27)
        FLD(TSW_STATE_RIGHT, TSW_STATE_RIGHT);
        STEP(28)
        FLD(TSW_STATE_LEFT, TSW_STATE_LEFT);
        STEP(29)
        FLD(TSW_STATE_DEFECT, TSW_STATE_DEFECT);
        STEP(30)
        FLD(TSW_STATE_RIGHT, TSW_STATE_RIGHT);
        STEP(31)
        FLD(TSW_STATE_DEFECT, TSW_STATE_DEFECT);
        STEP(32)
        FLD(TSW_STATE_UNDEF, TSW_STATE_UNDEF);
        STEP(33)
        CMD(TSW_GUI_GMD_LEFT, TSW_STATE_LEFT, TSW_STATE_WAIT_LEFT);
        STEP(34)
        FLD(TSW_STATE_LEFT, TSW_STATE_LEFT);
        STEP(35)
        CMD(TSW_GUI_GMD_RIGHT, TSW_STATE_RIGHT, TSW_STATE_WAIT_RIGHT);
        STEP(36)
        FLD(TSW_STATE_LEFT, TSW_STATE_LEFT);
        STEP(37)
        CMD(TSW_GUI_GMD_WU, TSW_STATE_RIGHT, TSW_STATE_WAIT_RIGHT);
        STEP(38)
        FLD(TSW_STATE_RIGHT, TSW_STATE_RIGHT);
        STEP(39)
        CMD(TSW_GUI_GMD_LEFT, TSW_STATE_LEFT, TSW_STATE_WAIT_LEFT);
        STEP(40)
        FLD(TSW_STATE_RIGHT, TSW_STATE_RIGHT);
        STEP(41)
        CMD(TSW_GUI_GMD_WU, TSW_STATE_LEFT, TSW_STATE_WAIT_LEFT);
        STEP(42)
        FLD(TSW_STATE_DEFECT, TSW_STATE_DEFECT);
        STEP(43)
        FLD(TSW_STATE_UNDEF, TSW_STATE_UNDEF);
        STEP(44)
        CMD(TSW_GUI_GMD_RIGHT, TSW_STATE_RIGHT, TSW_STATE_WAIT_RIGHT);
        STEP(45)
        FLD(TSW_STATE_DEFECT, TSW_STATE_DEFECT);
        STEP(46)
        FLD(TSW_STATE_UNDEF, TSW_STATE_UNDEF);
        STEP(47)
        CMD(TSW_GUI_GMD_RIGHT, TSW_STATE_RIGHT, TSW_STATE_WAIT_RIGHT);
        STEP(48)
        CMD(TSW_GUI_GMD_LEFT, TSW_STATE_LEFT, TSW_STATE_WAIT_LEFT);
        STEP(49)
        CMD(TSW_GUI_GMD_RIGHT, TSW_STATE_RIGHT, TSW_STATE_WAIT_RIGHT);
```

## sample: transitions SIG_H_N

### transition table
|FLD *||CMD H0 N0||CMD H0 N1||CMD H1 N0||CMD H1 N1||
|:---|:---|:---|:---|:---|:---|:---|:---|:---|:---|
|UNDEF|UNDEF|UNDEF|WAIT H0 N0|UNDEF|WAIT H0 N1|UNDEF|WAIT H1 N0|UNDEF|WAIT H1 N1|
|DEFECT|DEFECT|||||||||
|H0 N0|H0 N0|||H0 N0||H0 N0||H0 N0||
|H0 N1|H0 N1|H0 N1||||H0 N1||H0 N1||
|H1 N0|H1 N0|H1 N0||H1 N0||||H1 N0||
|H1 N1|H1 N1|H1 N1||H1 N1||H1 N1||||
|WAIT H0 N0||||WAIT H0 N0||WAIT H0 N0||WAIT H0 N0||
|WAIT H0 N1||WAIT H0 N1||||WAIT H0 N1||WAIT H0 N1||
|WAIT H1 N0||WAIT H1 N0||WAIT H1 N0||||WAIT H1 N0||
|WAIT H1 N1||WAIT H1 N1||WAIT H1 N1||WAIT H1 N1||||

### transitions & test steps

```
  82 transitions
 121 test steps total
  18 test steps without transition
  21 test steps as glue
```
