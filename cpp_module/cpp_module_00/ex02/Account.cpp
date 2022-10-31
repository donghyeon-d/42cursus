#include <unistd.h>
#include <iostream>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
    return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
    return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
    return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
    return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
    Account::_displayTimestamp();
    std::cout << "accounts:" << Account::_nbAccounts << ";" \
    << "total:" << Account::_totalAmount << ";" \
    << "deposits:" << Account::_totalNbDeposits << ";" \
    << "withdrawals:" << Account::_totalNbWithdrawals \
    << std::endl;
}


Account::Account(int initial_deposit)
{
    this->_accountIndex = this->_nbAccounts;
    this->_nbAccounts++;
	this->_amount = initial_deposit;
    this->_totalAmount += this->_amount;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
    this->_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";" \
    << "amount:" << this->_amount << ";" \
    << "created" << std::endl;
}

Account::~Account( void )
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";"\
    << "amount:" << this->_amount << ";"\
    << "closed" << std::endl;
}

void	Account::_displayTimestamp( void )
{
    std::cout << "[19920104_091532] ";
}

void	Account::displayStatus( void ) const
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";" \
    << "amount:" << this->_amount << ";" \
    << "deposits:" << this->_nbDeposits << ";" \
    << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void    Account::makeDeposit( int deposit )
{
    this->_totalAmount += deposit;
    this->_totalNbDeposits++;
    this->_nbDeposits++;
    this->_amount += deposit;
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";" \
    << "p_amount:" << this->_amount - deposit << ";" \
    << "deposit:" << deposit << ";" \
    << "amount:" << this->_amount << ";" \
    << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool    Account::makeWithdrawal( int withdrawal )
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";" \
    << "p_amount:" << this->_amount << ";" \
    << "withdrawal:";
    if (withdrawal > this->_amount)
    {
        std::cout << "refused" << std::endl;
        return (false);
    }
    else
    {
        this->_amount -= withdrawal;
        Account::_totalAmount -= withdrawal;
        Account::_totalNbWithdrawals++;
        this->_nbWithdrawals++;
        std::cout << withdrawal << ";" \
        << "amount:" << this->_amount << ";" \
        << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
        return (true);
    }
}

int     Account::checkAmount(void) const
{
    return (this->_amount);
}