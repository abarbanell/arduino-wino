---
layout: post
title:  "Welcome to Jekyll!"
date:   2015-10-31 14:22:30
categories: jekyll update
---
You’ll find this post in your `_posts` directory. Go ahead and edit it and re-build the site to see your changes. You can rebuild the site in many different ways, but the most common way is to run `jekyll serve`, which launches a web server and auto-regenerates your site when a file is updated.

To add new posts, simply add a file in the `_posts` directory that follows the convention `YYYY-MM-DD-name-of-post.ext` and includes the necessary front matter. Take a look at the source for this post to get an idea about how it works.

Jekyll also offers powerful support for code snippets:

{% highlight ruby %}
def print_hi(name)
  puts "Hi, #{name}"
end
print_hi('Tom')
#=> prints 'Hi, Tom' to STDOUT.
{% endhighlight %}

Check out the [Jekyll docs][jekyll] for more info on how to get the most out of Jekyll. File all bugs/feature requests at [Jekyll’s GitHub repo][jekyll-gh]. If you have questions, you can ask them on [Jekyll’s dedicated Help repository][jekyll-help].

## Notes to self

A few things about how to run this github pages site

## How to set up Jekyll for github pages in a project folder

Problem: To run Jekyll in a project directory you need to set the
baseurl to the name of your project, but for running locally this
needs to be empty.

Solution: 

_config.yml should contain the live configuration: 

```
baseurl: "/arduino-wino" # the subpath of your site, e.g. /blog/
```

but for running locally you need to override this via command line like so: 

```
$ bundle exec jekyll serve -b "" -V --drafts
```

Source for this tip: [https://github.com/jekyll/jekyll/issues/332](https://github.com/jekyll/jekyll/issues/332#issuecomment-18952908)


[jekyll]:      http://jekyllrb.com
[jekyll-gh]:   https://github.com/jekyll/jekyll
[jekyll-help]: https://github.com/jekyll/jekyll-help
