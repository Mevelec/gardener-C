
# Build an image
update the version in the build script and the run it
./build.sh

# Publish 
To publish the image to docker hub repo

## Connect to repo 
docker login -u elros37
## Push
docker push elros37/c_builder:0.0.2
- password is in keepass

# Helps
## Clean local docker Images
docker rmi $(docker images -q)
