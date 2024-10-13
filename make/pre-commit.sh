#!bash

py=$(which py)
if [[ -z $py ]]; then py=$(which python); fi
if [[ -z $py ]]; then py=$(which python3); fi
if [[ -z $py ]]; then exit 0; fi
echo "Using python: $py"

for file in `git diff-index --cached --name-only HEAD`;
do
  if [[ -f $file ]]
  then
    [[ $file == *.cpp ]] && isCpp=true || isCpp=false
    [[ $file == *.h ]] && isH=true || isH=false
    [[ $isCpp || $isH ]] && isSource=true || isSource=false

    echo $file

  fi
done
