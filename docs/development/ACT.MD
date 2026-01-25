# ACT
ACT is a workflow runner like Github Actions but local and a whole lot worse.

Here are the workarounds to get basic functionality.
I'm assuming you have docker and ACT installed

1. Create a container
- `docker run -it ubuntu:24.04 bash`
2. Install packages
- ```bash
  export DEBIAN_FRONTEND=noninteractive
  apt update
  apt install -y tzdata curl gnupg sudo
  curl -fsSL https://deb.nodesource.com/setup_20.x | bash -
  apt install -y nodejs
  ```
3. Note down the ID while in the container, should look like:
- `root@abcd1234abcd:/#` Your ID would be abcd1234abcd
4. Exit container
- `exit`
5. Save the container as an image
- `docker commit <ID> subuntu:latest`
- For Example:
    - `docker commit abcd1234abcd subuntu:latest`
6. Finally, you can run ACT
`act -j build --pull=false -P ubuntu-24.04=subuntu:latest --artifact-server-path $PWD/.artifacts`