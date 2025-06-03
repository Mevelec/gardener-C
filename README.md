# SampleProject
## Infos
The SampleProject project is a template for future c++ projects

### Compatibility
- Plateforms

## Installation
1. clone the project
4. Install git submoduls `git submodule init` `git submodule update` `git submodule add https://github.com/gabime/spdlog.git projects/vendor/spdlog`
2. get premake and put it in GameEngine/vendor/premake if not present or correct version
3. run the Gen script in the scripts folder 
4. you now have a visualstudio2019 project in root directory
## Build
Use make command from root folder
then use the generated bin ex : ./bin/Debug-linux-x86_64/HelloWorld/HelloWorld 

## Add submodule 
git submodule add https://github.com/gabime/spdlog.git projects/vendor/spdlog