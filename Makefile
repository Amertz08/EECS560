DK=docker
IMG_NAME=eecs560

build:
	$(DK) build -t $(IMG_NAME) .


run:
	$(DK) run -it --mount src=$(shell pwd),target=/code,type=bind \
	$(IMG_NAME)