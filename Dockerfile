FROM ubuntu

RUN apt-get update \
	&& apt-get install make gcc libreadline6-dev -y \
	&& mkdir /opt/minishell

COPY . /opt/minishell
WORKDIR /opt/minishell
RUN make \
	&& make clean

CMD ["./minishell"];
