// Workshop 9 - Multi-Threading, Thread Class
// process_data.cpp
// 2021/1/5 - Jeevan Pant

#include <algorithm>
#include <numeric>
#include "process_data.h"
using namespace std::placeholders;

namespace sdds_ws9 {

	void computeAvgFactor(const int* arr, int size, int divisor, double& avg) {
		avg = 0;
		for (int i = 0; i < size; i++) {
			avg += arr[i];
		}
		avg /= divisor;
	}

	void computeVarFactor(const int* arr, int size, int divisor, double avg, double& var) {
		var = 0;
		for (int i = 0; i < size; i++) {
			var += (arr[i] - avg) * (arr[i] - avg);
		}
		var /= divisor;
	}
	ProcessData::operator bool() const {
		return total_items > 0 && data && num_threads > 0 && averages && variances && p_indices;
	}

	
	ProcessData::ProcessData(std::string filename, int n_threads) {
		// TODO: Open the file whose name was received as parameter and read the content
		//         into variables "total_items" and "data". Don't forget to allocate
		//         memory for "data".
		//       The file is binary and has the format described in the specs.

		//open the file
		std::ifstream fin(filename, std::ios::in | std::ios::binary);
		if (!fin) {
			throw std::invalid_argument("Cannot open file");
		}
		if (fin.is_open()) {
			fin.read(reinterpret_cast<char*>(&total_items), sizeof(total_items));

			std::vector<int> temp_data(total_items);
			fin.read(reinterpret_cast<char*>(temp_data.data()), total_items * sizeof(int));
			
			data = new int[total_items];
			for (int i = 0; i < total_items; i++) {
				data[i] = temp_data[i];
			}
		}

			std::cout << "Item's count in file '" << filename << "': " << total_items << std::endl;
			std::cout << "  [" << data[0] << ", " << data[1] << ", " << data[2] << ", ... , "
				<< data[total_items - 3] << ", " << data[total_items - 2] << ", "
				<< data[total_items - 1] << "]\n";

			// Following statements initialize the variables added for multi-threaded 
			//   computation
			num_threads = n_threads;
			averages = new double[num_threads] {};
			variances = new double[num_threads] {};
			p_indices = new int[num_threads + 1] {};
			for (int i = 0; i < num_threads + 1; i++)
				p_indices[i] = i * (total_items / num_threads);

	}

	ProcessData::~ProcessData() {
		delete[] data;
		delete[] averages;
		delete[] variances;
		delete[] p_indices;
	}

	// TODO Improve operator() function from part-1 for multi-threaded operation. Enhance the  
	//   function logic for the computation of average and variance by running the 
	//   function computeAvgFactor and computeVarFactor in multile threads. 
	// The function divides the data into a number of parts, where the number of parts is 
	//   equal to the number of threads. Use multi-threading to compute average-factor for 
	//   each part of the data by calling the function computeAvgFactor. Add the obtained 
	//   average-factors to compute total average. Use the resulting total average as the 
	//   average value argument for the function computeVarFactor, to compute variance-factors 
	//   for each part of the data. Use multi-threading to compute variance-factor for each 
	//   part of the data. Add computed variance-factors to obtain total variance.
	// Save the data into a file with filename held by the argument fname_target. 
	// Also, read the workshop instruction.
	int ProcessData::operator()(std::string filename, double& avg, double& var) {
		auto computeAvg = std::bind(computeAvgFactor, _1, p_indices[1], total_items, _2);
		auto computeVar = std::bind(computeVarFactor, _1, p_indices[1], total_items, std::ref(avg), _2);

		// compute avg
		std::vector<std::thread> process_Avg;
		for (int i = 0; i < num_threads; i++) {
			process_Avg.push_back(std::thread(computeAvg, &data[p_indices[i]], std::ref(averages[i])));
		}
		// join threads in process_Avg vector
		std::for_each(process_Avg.begin(), process_Avg.end(), [](std::thread& t) {
			t.join();
			});
		for (int i = 0; i < num_threads; i++) {
			avg += averages[i];
		}

		//compute var
		std::vector<std::thread> process_Var;
		for (int i = 0; i < num_threads; i++) {
			process_Var.push_back(std::thread(computeVar, &data[p_indices[i]], std::ref(variances[i])));
		}
		// join threads in process_Avg vector
		std::for_each(process_Var.begin(), process_Var.end(), [](std::thread& t) {
			t.join();
			});

		for (int i = 0; i < num_threads; i++) {
			var += variances[i];
		}

		// write data
		int res = 0;
		std::ofstream fout(filename, std::ios::out | std::ios::binary);
		if (fout.is_open()) {
			fout.write(reinterpret_cast<const char*>(&total_items), sizeof(total_items));
			for (int i = 0; i < total_items; i++) {
				fout.write(reinterpret_cast<const char*>(&data[i]), sizeof(data[i]));
			}
			res = 1;
		}
		else {
			throw std::invalid_argument("cannot open file");
		}
		return res;
	}



}