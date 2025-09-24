public static void main(String[] args) throws InterruptedException {
//    ResourcesExploiter resource = new ResourcesExploiter(0);
//
//    ThreadedWorkerWithoutSync worker1 = new ThreadedWorkerWithoutSync(resource);
//    ThreadedWorkerWithoutSync worker2 = new ThreadedWorkerWithoutSync(resource);
//    ThreadedWorkerWithoutSync worker3 = new ThreadedWorkerWithoutSync(resource);
//
//    worker1.start();
//    worker2.start();
//    worker3.start();
//    worker1.join();
//    worker2.join();
//    worker3.join();
//    System.out.println(resource.getRsc());
// Worker with sync
    ResourcesExploiter resource2 = new ResourcesExploiter(0);

    ThreadedWorkerWithSync worker4 = new ThreadedWorkerWithSync(resource2);
    ThreadedWorkerWithSync worker5 = new ThreadedWorkerWithSync(resource2);
    ThreadedWorkerWithSync worker6 = new ThreadedWorkerWithSync(resource2);

    worker4.start();
    worker5.start();
    worker6.start();
    worker4.join();
    worker5.join();
    worker6.join();
    System.out.println(resource2.getRsc());

//    ResourcesExploiterWithLock resource3 = new ResourcesExploiterWithLock(0);
//
//    ThreadedWorkerWithLock worker7 = new ThreadedWorkerWithLock(resource3);
//    ThreadedWorkerWithLock worker8 = new ThreadedWorkerWithLock(resource3);
//    ThreadedWorkerWithLock worker9 = new ThreadedWorkerWithLock(resource3);
//
//    worker7.start();
//    worker8.start();
//    worker9.start();
//    worker7.join();
//    worker8.join();
//    worker9.join();
//    System.out.println(resource3.getRsc());
}