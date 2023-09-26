# e164normalise

## Description
'e164normalise' is a simple command line utility program which 
takes two command line arguments: a) phone number to normalise to
E164 format and b) specified country and simply outputs the inputted number
in E164 format based on the selected country.

## Install

### Clone the repository
git clone https://github.com/binspammer/e164normalise.git

### Prerequisite
- cmake
- ninja
- GoogleTest

### Build
```
$ cd e164normalise
$ cmake -C build
$ ninja -C build
```

### Run Unit Tests
```
$ ./build/normalise_unittest
```

## Using example
```
$ ./build/normalise 02035100500 UK
```
