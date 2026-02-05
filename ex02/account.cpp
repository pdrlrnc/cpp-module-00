#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>
#include <ostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

static void display_timestamp(void)
{
	//get current UNIX time
	std::time_t now = std::time(NULL);
	//breaks it into human readable components
	std::tm *lt = std::localtime(&now);

	//setfill is a function that pads with zeros so 9am should be 09
	//tm_year - years since 1900
	//tm_mon - months since january (0 - 11)
	//tm_mday - day of month
	//tm_hour - hour (0-23)
	//tm_min - minutes
	//tm_sec - seconds
	std::cout 
		<< "["
		<< (lt->tm_year + 1900)
		<< std::setw(2) << std::setfill('0') << (lt->tm_mon + 1) 
		<< std::setw(2) << std::setfill('0') << lt->tm_mday
        	<< "_"
        	<< std::setw(2) << std::setfill('0') << lt->tm_hour
        	<< std::setw(2) << std::setfill('0') << lt->tm_min
        	<< std::setw(2) << std::setfill('0') << lt->tm_sec
		<< "] ";
}

Account::Account(int initial_deposit)
	:
		_accountIndex(_nbAccounts),
		_amount(initial_deposit),
		_nbDeposits(0),
		_nbWithdrawals(0)
		{
			display_timestamp();
			std::cout
			<< "index:" << _accountIndex
			<< ";amount:" << initial_deposit
			<< ";created" << std::endl;
			_totalAmount += initial_deposit;
			_nbAccounts++;
		}

Account::Account()
	:
		_accountIndex(_nbAccounts),
		_amount(0),
		_nbDeposits(0),
		_nbWithdrawals(0)
		{
			_nbAccounts++;
		}

Account::~Account() 
{
	display_timestamp();
	std::cout
		<< "index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";closed" << std::endl;
}

void Account::makeDeposit(int deposit)
{
	display_timestamp();
	std::cout
		<< "index:" << _accountIndex
		<< ";p_amount:" << _amount
		<< ";deposit:" << deposit;
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout
		<< ";amount:" << _amount
		<< ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	display_timestamp();
	std::cout
		<< "index:" << _accountIndex
		<< ";p_amount:" << _amount
		<< ";withdrawal:";
	if (_amount < withdrawal)
	{
		std::cout
			<< "refused" << std::endl;
		return (false);
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	std::cout
		<< withdrawal
		<< ";amount:" << _amount
		<< ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
}


int Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void)
{
	display_timestamp();
	std::cout
		<< "accounts:" << _nbAccounts
		<< ";total:" << _totalAmount
		<< ";deposits:" << _totalNbDeposits
		<< ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::displayStatus(void) const
{
	display_timestamp();
	std::cout
		<< "index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";deposits:" << _nbDeposits
		<< ";withdrawals:" << _nbWithdrawals << std::endl;
}
