PATH=$HOME/.brew/opt/ruby/bin/rails:$HOME/.brew/bin:/$HOME/.brew/opt/nginx/sbin:$HOME/mamp/php/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/opt/X11/bin:/usr/texbin:~/mamp/mysql/bin
PATH=$HOME/.gem/bin:$PATH
export GEM_HOME=$HOME/.gem
export GEM_PATH=$HOME/.gem
HISTFILE=~/.zshrc_history
SAVEHIST=5000
HISTSIZE=5000

setopt inc_append_history
setopt share_history

if [[ -f ~/.myzshrc ]]; then
	source ~/.myzshrc
fi

USER=`/usr/bin/whoami`
export USER
GROUP=`/usr/bin/id -gn $user`
export GROUP
MAIL="$USER@student.42.fr"
export MAIL

autoload -U compinit
compinit

autoload -U promptinit
promptinit
prompt adam2

alias gc='gcc -Wall -Wextra -Werror'
alias norme='norminette'
alias lsla='ls -la'
alias check='grep --include=\*.{c,h} -rnw '.' -e'
alias checkleaks='valgrind --tool=memcheck --leak-check=yes|no|full|summary --leak-resolution=low|med|high --show-reachable=yes'
alias subl="~/Desktop/Sublime\ Text.app/Contents/SharedSupport/bin/subl"
