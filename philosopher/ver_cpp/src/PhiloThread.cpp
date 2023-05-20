// #include "../include/Philo.hpp"
// #include <thread>

// void* ThreadMainFunc(void* parm)
// {
// 	Philo* philo = reinterpret_cast<Philo*>(parm);
//     philo->SpendTime(10);
//     while(true)
//     {
//         philo->GrabForks();
//         philo->Eatting();
//         philo->Sleeping();
//         if (philo->CheckStatus(END))
//         {
//             break;
//         }
//     }
// }

// class PhiloThread
// {
// 	public :
// 		PhiloThread(Philo* philo){
// 			_pthread = new pthread_t();
// 			_philo = philo;
// 		}
// 		void Start() {
// 			pthread_create(_pthread, NULL, Act, );
// 		}

// 	private :
// 		pthread_t	*_pthread;
// 		Philo* _philo;
// }