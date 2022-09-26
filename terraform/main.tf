resource "aws_security_group" "allow-tcp" {
  name = "my-aws-terraform-hello-world"
  ingress {
    from_port = 8080
    to_port = 8080
    protocol = "tcp"
    cidr_blocks = ["0.0.0.0/0"]
  }
}

resource "aws_instance" "hello-world" {
  ami = "ami-ef92b08a"
  instance_type = "t2.micro"

  provisioner "file" {
    source = "webservice"
    destination = "~"
  }
  provisioner "local-exec" {
    command = <<EOH
      sudo yum -y update
      sudo yum install -y python3.6
      python3 webservice/serv.py
    EOH
  }

  tags {
    Name = "my-aws-terraform-hello-world"
  }
}

output "my-public-ip"{
       value= aws_instance.instance.public_ip
}
