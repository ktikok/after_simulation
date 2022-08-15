import pickle

def get_average_time(simulation_material, simulation_energy,number_of_logs, start_number_of_logs, threshold_time, print_flag):
    if simulation_material == 'copper':
        derectory_name = '/fcc/tikim/results/ele/'+simulation_material+'/e_'+str(simulation_energy)+'GeV_51th/log/'
    else:
        derectory_name = '/fcc/tikim/results/ele/'+simulation_material+'/e_'+str(simulation_energy)+'GeV_0th/log/'
    # for k in range(start_number_of_logs, 2):
    total_day = 0
    total_hour = 0
    total_minute = 0
    total_sec = 0
    max_time = 0
    min_time = 99999999999999999999
    number_of_count = 0
    for k in range(start_number_of_logs,start_number_of_logs + number_of_logs):

        file_name = derectory_name + str(k)+'.log'
        # print(file_name)
        show_info = 0

        with open(file_name,'r') as f:
            # print(f)
            for i in f:
                if 'Job terminated' in i:
                    show_info = show_info+1
                    # print(i)
                if show_info != 0:
                    show_info = show_info+1
                    if show_info == 6:
                        # print(file_name[22:],':',i[4:-1])
                        day = int(i[5:7])
                        hour = int(i[8:10])
                        minute = int(i[11:13])
                        sec = int(i[14:16])
                        to_sec = day*24*60*60 + hour*3600 + minute*60 +sec
                        # print(to_sec)
                        if max_time < to_sec:
                            max_time = to_sec

                        if to_sec > threshold_time:
                            if min_time > to_sec:
                                min_time = to_sec
                            number_of_count = number_of_count +1
                            total_day = total_day + day
                            total_hour = total_hour + hour
                            total_minute = total_minute + minute
                            total_sec = total_sec + sec
                        # print(hour)

    # total_time_s = total_hour*3600+total_minute*60+total_sec\
    average_time_s = (total_day*24*60*60 + total_hour*3600 + total_minute*60 + total_sec)/number_of_count
    final_day = average_time_s // (24*60*60)
    final_hour = (average_time_s % (24*60*60)) // 3600
    final_minute = (average_time_s % 3600)//60
    final_sec = average_time_s % 60
    if print_flag ==1:
        print(simulation_material, str(simulation_energy)+'GeV','count:', number_of_count, 'max:',max_time,'ave:',average_time_s,', min:', min_time,',','time:',final_day, final_hour,':',final_minute,':',final_sec)
    return [average_time_s, max_time, [simulation_material, str(simulation_energy)+'GeV','count:', number_of_count, 'max:',max_time,'ave:',average_time_s,', min:', min_time,',','time:',final_day, final_hour,':',final_minute,':',final_sec]]

number_of_logs = 500
start_number_of_logs = 0
simulation_material = 'brass'
simulation_energy = 5
# derectory_name = '/fcc/tikim/results/ele/'+simulation_material+'/e_5GeV_0th/log/'
# file_name = '/fcc/tikim/results/ele/brass/e_5GeV_0th/log/0.log'
threshold_time = 0


# list_of_times = []
# for simulation_energy in [70]:
for simulation_material in ['tungsten', 'tungsten_theta3']:
# for simulation_material in ['lead', 'tungsten', 'tungsten_theta3']:
    print("Start "+simulation_material+"! (It takes long time.)")
    # with open('timetable.txt', 'a') as fp:
    #     fp.write("%s\n" % str(simulation_material))
    for simulation_energy in [5, 10, 20, 30, 50, 70]:
        # if simulation_energy < 50:
        #     continue
        print('Please wait..')
        average_and_max = get_average_time(simulation_material, simulation_energy, number_of_logs, start_number_of_logs, threshold_time, 0)
        print('Please wait..')
        average_and_max1 = get_average_time(simulation_material, simulation_energy, number_of_logs, start_number_of_logs, average_and_max[0]-(average_and_max[1]-average_and_max[0]), 0)
        # break

        while(1):
            # print('hi')
            if average_and_max == average_and_max1:
                print(average_and_max)
                # list_of_times.append(average_and_max)
                with open('timetable.txt', 'a') as fp:
                    fp.write("%s\n" % str(average_and_max))
                break
            else:
                average_and_max = average_and_max1
                print('Please wait..')
                average_and_max1 = get_average_time(simulation_material, simulation_energy, number_of_logs, start_number_of_logs, average_and_max1[0]-(average_and_max1[1]-average_and_max1[0]), 0)

# with open('timetable.txt', 'a') as fp:
#     # for i in list_of_times:
#         fp.write("%s\n" % str(i))
print("done")

# print(total_hour+total_minute//60,':',total_minute%60+total_sec//60,':',total_sec%60)
