CURDIR=$(shell pwd)

SRCDIR=$(CURDIR)/src
INCLUDEDIR=$(CURDIR)/include

$(info "custom include dir $(INCLUDEDIR)")
$(info "custom src dir $(SRCDIR)")

srcfile=$(wildcard $(SRCDIR)/*.cc)
obj=$(patsubst %.cc, %.o, $(srcfile))

INCLUDES += -I$(INCLUDEDIR)/

ALL: main.out

$(obj): %.o:%.cc
	g++ -c $< -o $@ $(INCLUDES)

main.out: $(obj)
	g++ -g $^ -o $@ $(INCLUDES)

clean:
	-rm -rf $(obj) main.out

.PHONY: clean ALL

