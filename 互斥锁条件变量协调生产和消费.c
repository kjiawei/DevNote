#include <stdio.h>
#include <pthread.h>
#include <signal.h>

int i, flag;
pthread_mutex_t mutex;
pthread_cond_t cond;

void gameover( int sig )
{
	flag = 1;
	pthread_cond_signal( &cond );
}

/*线程一，生产者*/
void *f1( void *arg )
{
	while( !flag )
	{
		pthread_mutex_lock( &mutex );

		/*当i等于10后给消费者发送信号，并停止生产*/
		if( i == 10 )
		{
			pthread_cond_signal( &cond );
			pthread_cond_wait( &cond, &mutex );
		}

		printf("now in thread1, i = %d\n", ++i );
		usleep( 600000 );
		pthread_mutex_unlock( &mutex );
		
	}

	pthread_exit( NULL );
}

/*线程二，消费者*/
void *f2( void *arg )
{
	/*假如消费者先抢到锁了，就解锁并等待生产者发送信号*/
	pthread_mutex_lock( &mutex );// 阻塞
	pthread_cond_wait( &cond, &mutex );//
	pthread_mutex_unlock( &mutex );

	while( !flag )
	{
		pthread_mutex_lock( &mutex );

		/*当i等于0后给生产者发送信号，并停止消费*/
		if( i < 1 )
		{
			pthread_cond_signal( &cond );
			pthread_cond_wait( &cond, &mutex );
		}

		printf("   now in thread2, i = %d\n", --i );
		usleep( 600000 );
		pthread_mutex_unlock( &mutex );
	}

	pthread_exit( NULL );
}

int main( void )
{
	pthread_t pid1, pid2;

	pthread_mutex_init( &mutex, NULL );
	pthread_cond_init( &cond, NULL );

	pthread_create( &pid1, NULL, f1, NULL );
	pthread_create( &pid2, NULL, f2, NULL );

	signal( SIGINT, gameover );

	pthread_join( pid1, NULL );
	pthread_join( pid2, NULL );
	pthread_mutex_destroy( &mutex );
	pthread_cond_destroy( &cond );

	return 0;
}