public static void main(String[] args) {
    ResourcesExploiter resource = new ResourcesExploiter(0);

    ThreadedWorkerWithoutSync worker1 = new ThreadedWorkerWithoutSync(resource);
    ThreadedWorkerWithoutSync worker2 = new ThreadedWorkerWithoutSync(resource);
    ThreadedWorkerWithoutSync worker3 = new ThreadedWorkerWithoutSync(resource);

    worker1.start();
    System.out.println(resource.getRsc());
    worker2.start();
    System.out.println(resource.getRsc());
    worker3.start();
    System.out.println(resource.getRsc());


}