# Twitter dataset text pattern finder

### How to compile?
- Create a `build/` dir
  - `mkdir build`
- Move to that dir
  - `cd build`
- Run `cmake ..`
  - This will generate the adequate make files
- Lastly, run `make`

### How to run?
After you've compiled, run `./patterns` if you're in the `build/` directory, or `./build/patterns` if you're in the root dir.

### How to use it?
=== You must have your datoasets in the `datasets/` directory. ===

The program will show you a list with the datasets under that directory. It will prompt you pick one of them, either by name or id. After you choose the dataset, you will have to input the regular expresion with the given format. Lastly, it will show the results of the query.