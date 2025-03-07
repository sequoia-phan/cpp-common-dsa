Establishing a ssh connection to github.

1. create a key pairs ssh-keygen -t[type] rsa|ed25519|... -C[comment] "email"
2. add .pub key file to ssh client (github)
3. check connection correctly ssh -T git@github.com (if not then follows to step 4) 
4. start a new ssh agent eval "$(ssh-agent -s)"
5. add your key to ssh agent ssh-add ~/.ssh/id_ed25519 then test in step 3
if it prints "Hi your-username! You've successfully authenticated, but GitHub does not provide shell access." congrats you
!!! check you're using ssh or https - git remote -v
Unless https then set to ssh - git remote set-url origin git@github.com:your-username/your-repo.git
-> now you can push your code :)) happy coding!!! 

@author - sequoia-phan
@credential - github docs
