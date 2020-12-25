CFLAGS = -Wall -Wextra -std=c99 -g
CPPFLAGS = -I.
LDFLAGS =

EXEC = main

all: $(EXEC) ru/LC_MESSAGES/$(EXEC).mo


$(EXEC): $(EXEC).c
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ $< $(LDFLAGS)

ru/LC_MESSAGES/$(EXEC).mo: po/ru/$(EXEC).po
	if ! [ -d "ru" ]; then mkdir ru; fi && if ! [ -d "ru/LC_MESSAGES" ]; then mkdir ru/LC_MESSAGES; fi && msgfmt --output-file=$@ $<

po/ru/$(EXEC).po: po/$(EXEC).pot
	msgmerge --update $@ $<

po/$(EXEC).pot: $(EXEC).c
	touch po/main.pot && xgettext -k_ -j -lC -c -s -o po/main.pot main.c

clean:
	@rm po/main.pot && rm -r ru

.PHONY: clean
