# ft_services
This project consist to clusturing an docker-compose application and deploy it with Kubernetes.

# Objectives

- Network & system administration
- Docker
- Kubernetes

# Usage
# Create a pod from a YAML file
kubectl create -f <yourfile.yaml>

# Delete a pod
kubectl delete deployment <your deployment>
kubectl delete service <your service>
# and so on if you have different objects

# Get a shell in a pod
# First get the pod full name with:
kubectl get pods
# Then, your pod name should look like "grafana-5bbf569f68-svdnz"
kubectl exec -it <pod name> -- /bin/sh

# Copy data to pod or to our computer
kubectl cp <pod name>:<file> <to>
# or vice versa
kubectl cp <from> <pod name>:<to>

# Restart a deployment
kubectl rollout restart deployment <name>

# Launch minikube dashboard
minikube dashboard

# Get cluster external IP
minikube ip

# Reset Minikube VM
minikube delete

# Connect nginx via ssh
ssh <user>@<external ip of nginx>

# Show all services
kubectl get svc

# Delete an image:
docker rmi <image name>

# Kill services in containers
kubectl exec deploy/<your service> -- pkill <process name>
