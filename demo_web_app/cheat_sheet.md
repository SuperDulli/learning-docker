# cleaning
`docker container ls -a` - view all containers
`docker container rm $(docker container ls -aq)` - remove all non-running containers
`docker volume prune` - remove all unused volumes