#!/bin/bash -xe
git config core.hooksPath git-hooks
PROJECT_HOME=$(git rev-parse --show-toplevel)
#cd $PROJECT_HOME/.git/hooks/pre-push
ln -sf $PROJECT_HOME/git-hooks/pre-push $PROJECT_HOME/.git/hooks/pre-push

