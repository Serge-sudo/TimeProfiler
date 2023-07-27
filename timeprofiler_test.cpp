#include <myThreadClass/myThreadClass.hpp>
#include <queuelt/queuelt.hpp>
#include <queueat/queueat.hpp>


#include <timeprofiler/timeprofiler.hpp>
#include <random>

#define CNT 10

struct TestStruct {
    int key;
    int value;
};

int compareTestStruct(const TestStruct *pElement, const TestStruct *pElement2) {
    return pElement->key - pElement2->key;
}

void warm_up() {
    std::vector<TestStruct> ts;
    for (int i = 0; i < 100000000; i++) {
        ts.push_back(TestStruct{i, i});
    }
    for (int i = 0; i < 100000000; i++) {
        ts.pop_back();
    }
}

long thread_with_profiler() {
    PROFILE_ON();
    const auto start = std::chrono::high_resolution_clock::now();
    for (int m = 0; m < CNT; m++) {
        MyThreadClass t;
        t.start();
    }
    const auto end = std::chrono::high_resolution_clock::now();
    const auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    return duration.count() / CNT;
}

long thread_without_profiler() {
    PROFILE_OFF();
    const auto start = std::chrono::high_resolution_clock::now();
    for (int m = 0; m < CNT; m++) {
        MyThreadClass t;
        t.start();
    }
    const auto end = std::chrono::high_resolution_clock::now();
    const auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    return duration.count() / CNT;
}




long queuaA_with_profiler() {
    PROFILE_ON();
    const auto start = std::chrono::high_resolution_clock::now();
    for (int m = 0; m < CNT; m++) {
        QueueA<TestStruct> q;
        for (int i = 0; i < 1000000; i++) {
            q.push(TestStruct{i, i});
        }
        for (int i = 0; i < 1000000; ++i) {
            q.pop();
        }
    }
    const auto end = std::chrono::high_resolution_clock::now();
    const auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    return duration.count() / CNT;
}

long queuaA_without_profiler() {
    PROFILE_OFF();
    const auto start = std::chrono::high_resolution_clock::now();
    for (int m = 0; m < CNT; m++) {
        QueueA<TestStruct> q;
        for (int i = 0; i < 1000000; i++) {
            q.push(TestStruct{i, i});
        }
        for (int i = 0; i < 1000000; ++i) {
            q.pop();
        }

    }
    const auto end = std::chrono::high_resolution_clock::now();
    const auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    return duration.count() / CNT;
}


long queuaL_with_profiler() {
    PROFILE_ON();
    const auto start = std::chrono::high_resolution_clock::now();
    for (int m = 0; m < CNT; m++) {
        QueueL<TestStruct> q;
        for (int i = 0; i < 1000000; i++) {
            q.push(TestStruct{i, i});
        }
        for (int i = 0; i < 1000000; ++i) {
            q.pop();
        }
    }
    const auto end = std::chrono::high_resolution_clock::now();
    const auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    return duration.count() / CNT;
}

long queuaL_without_profiler() {
    PROFILE_OFF();
    const auto start = std::chrono::high_resolution_clock::now();
    for (int m = 0; m < CNT; m++) {
        QueueL<TestStruct> q;
        for (int i = 0; i < 1000000; i++) {
            q.push(TestStruct{i, i});
        }
        for (int i = 0; i < 1000000; ++i) {
            q.pop();
        }
    }
    const auto end = std::chrono::high_resolution_clock::now();
    const auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    return duration.count() / CNT;
}


long queuaA_with_profiler_push_pop() {
    PROFILE_ON();
    const auto start = std::chrono::high_resolution_clock::now();
    for (int m = 0; m < CNT; m++) {
        QueueA<TestStruct> q;
        for (int i = 0; i < 1000000; i++) {
            q.push(TestStruct{i, i});
            q.pop();
        }
    }
    const auto end = std::chrono::high_resolution_clock::now();
    const auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    return duration.count() / CNT;
}

long queuaA_without_profiler_push_pop() {
    PROFILE_OFF();
    const auto start = std::chrono::high_resolution_clock::now();
    for (int m = 0; m < CNT; m++) {
        QueueA<TestStruct> q;
        for (int i = 0; i < 1000000; i++) {
            q.push(TestStruct{i, i});
            q.pop();
        }

    }
    const auto end = std::chrono::high_resolution_clock::now();
    const auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    return duration.count() / CNT;
}


long queuaL_with_profiler_push_pop() {
    PROFILE_ON();
    const auto start = std::chrono::high_resolution_clock::now();
    for (int m = 0; m < CNT; m++) {
        QueueL<TestStruct> q;
        for (int i = 0; i < 1000000; i++) {
            q.push(TestStruct{i, i});
            q.pop();
        }

    }
    const auto end = std::chrono::high_resolution_clock::now();
    const auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    return duration.count() / CNT;
}

long queuaL_without_profiler_push_pop() {
    PROFILE_OFF();
    const auto start = std::chrono::high_resolution_clock::now();
    for (int m = 0; m < CNT; m++) {
        QueueL<TestStruct> q;
        for (int i = 0; i < 1000000; i++) {
            q.push(TestStruct{i, i});
            q.pop();
        }
    }
    const auto end = std::chrono::high_resolution_clock::now();
    const auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    return duration.count() / CNT;
}


long queuaA_with_profiler_push_pop_push_pop() {
    PROFILE_ON();
    const auto start = std::chrono::high_resolution_clock::now();
    for (int m = 0; m < CNT; m++) {
        QueueA<TestStruct> q;
        for (int i = 0; i < 250000; i++) {
            q.push(TestStruct{i, i});

        }
        for (int i = 0; i < 250000; i++) {
            q.pop();
        }
        for (int i = 0; i < 250000; i++) {
            q.push(TestStruct{i, i});

        }
        for (int i = 0; i < 250000; i++) {
            q.pop();
        }
    }
    const auto end = std::chrono::high_resolution_clock::now();
    const auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    return duration.count() / CNT;
}

long queuaA_without_profiler_push_pop_push_pop() {
    PROFILE_OFF();
    const auto start = std::chrono::high_resolution_clock::now();
    for (int m = 0; m < CNT; m++) {
        QueueA<TestStruct> q;
        for (int i = 0; i < 250000; i++) {
            q.push(TestStruct{i, i});

        }
        for (int i = 0; i < 250000; i++) {
            q.pop();
        }
        for (int i = 0; i < 250000; i++) {
            q.push(TestStruct{i, i});

        }
        for (int i = 0; i < 250000; i++) {
            q.pop();
        }

    }
    const auto end = std::chrono::high_resolution_clock::now();
    const auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    return duration.count() / CNT;
}


long queuaL_with_profiler_push_pop_push_pop() {
    PROFILE_ON();
    const auto start = std::chrono::high_resolution_clock::now();
    for (int m = 0; m < CNT; m++) {
        QueueL<TestStruct> q;
        for (int i = 0; i < 250000; i++) {
            q.push(TestStruct{i, i});

        }
        for (int i = 0; i < 250000; i++) {
            q.pop();
        }
        for (int i = 0; i < 250000; i++) {
            q.push(TestStruct{i, i});

        }
        for (int i = 0; i < 250000; i++) {
            q.pop();
        }

    }
    const auto end = std::chrono::high_resolution_clock::now();
    const auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    return duration.count() / CNT;
}

long queuaL_without_profiler_push_pop_push_pop() {
    PROFILE_OFF();
    const auto start = std::chrono::high_resolution_clock::now();
    for (int m = 0; m < CNT; m++) {
        QueueL<TestStruct> q;
        for (int i = 0; i < 250000; i++) {
            q.push(TestStruct{i, i});

        }
        for (int i = 0; i < 250000; i++) {
            q.pop();
        }
        for (int i = 0; i < 250000; i++) {
            q.push(TestStruct{i, i});

        }
        for (int i = 0; i < 250000; i++) {
            q.pop();
        }
    }
    const auto end = std::chrono::high_resolution_clock::now();
    const auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    return duration.count() / CNT;
}


void test1() {
    std::cout << "MEASURING QueuaA WITH PROFILER TOKE: " << queuaA_with_profiler() << " μs" << std::endl;
    std::cout << "MEASURING QueuaA WITHOUT PROFILER TOKE: " << queuaA_without_profiler() << " μs" << std::endl;
    std::cout << "MEASURING QueuaL WITH PROFILER TOKE: " << queuaL_with_profiler() << " μs" << std::endl;
    std::cout << "MEASURING QueuaL WITHOUT PROFILER TOKE: " << queuaL_without_profiler() << " μs" << std::endl;
}

void test2() {
    std::cout << "MEASURING QueuaA-push-pop WITH PROFILER TOKE: " << queuaA_with_profiler_push_pop() << " μs"
              << std::endl;
    std::cout << "MEASURING QueuaA-push-pop WITHOUT PROFILER TOKE: " << queuaA_without_profiler_push_pop() << " μs"
              << std::endl;
    std::cout << "MEASURING QueuaL-push-pop WITH PROFILER TOKE: " << queuaL_with_profiler_push_pop() << " μs"
              << std::endl;
    std::cout << "MEASURING QueuaL-push-pop WITHOUT PROFILER TOKE: " << queuaL_without_profiler_push_pop() << " μs"
              << std::endl;

}

void test3() {
    std::cout << "MEASURING QueuaA-push-pop-push-pop WITH PROFILER TOKE: "
              << queuaA_with_profiler_push_pop_push_pop() << " μs" << std::endl;
    std::cout << "MEASURING QueuaA-push-pop-push-pop WITHOUT PROFILER TOKE: "
              << queuaA_without_profiler_push_pop_push_pop() << " μs" << std::endl;
    std::cout << "MEASURING QueuaL-push-pop-push-pop WITH PROFILER TOKE: "
              << queuaL_with_profiler_push_pop_push_pop() << " μs" << std::endl;
    std::cout << "MEASURING QueuaL-push-pop-push-pop WITHOUT PROFILER TOKE: "
              << queuaL_without_profiler_push_pop_push_pop() << " μs" << std::endl;
}


void test4() {
    std::cout << "MEASURING THREAD WITH PROFILER TOKE: " << thread_with_profiler() << " μs" << std::endl;
    std::cout << "MEASURING THREAD WITHOUT PROFILER TOKE: " << thread_without_profiler() << " μs" << std::endl;
}



int main() {
    warm_up();
//    test1();
//    test2();
//    test3();
    test4();
}