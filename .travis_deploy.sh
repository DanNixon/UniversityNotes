#!/bin/bash

# Don't publish for a pull request or a non-master branch
if [ "$TRAVIS_PULL_REQUEST" != "false" -o "$TRAVIS_BRANCH" != "master" ];
then
  echo Not publishing PDFs.
  exit 0;
fi

git config --global user.email "nobody@nobody.org"
git config --global user.name "Travis CI"

cd out
git init

git add CSC*.pdf *.html
git commit -m "Deploy PDFs"
git push --force --quiet "https://${GH_TOKEN}@${GH_REF}" master:gh-pages > /dev/null 2>&1
