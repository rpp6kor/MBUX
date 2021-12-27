# Simple intent recogniton command line tool

 This is the small description on how to use the intent recognition tool.
 This tool gets the intent based on the inputs provided by the user.

# Command to clone the tool from github
- [SSH]
  git@github.com:rpp6kor/MBUX.git

- [HTTPS]
  git clone https://github.com/rpp6kor/MBUX.git

# How to build the tool
  Once the cloning is done, cd to MBUX and use the below command to build the tool
  mkdir build && cd build && cmake .. && make

# How to use the tool
  ./MBITION

  once the tool is run, the user is prompted to enter his/her question, once the question is entered the intent is returned.
  The tool is registered with some of the variations, hence for those the tool gives the right intent, for others it says "Try something else ..."
  The tool is run in the infinite loop, hence use SIGINT (ctrl+c) to close the tool.

# How to run the tests
  ./intent_recognition_test
  ./speech_service_test

# PR
  https://github.com/rpp6kor/MBUX/tree/mbition_mbux_test
  https://github.com/rpp6kor/MBUX/pull/2
